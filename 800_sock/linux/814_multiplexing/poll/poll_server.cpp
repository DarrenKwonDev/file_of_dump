#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>
#include <poll.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

#define PORT 8080
#define MAX_CLIENTS 30

int main() {
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    std::vector<struct pollfd> fds;
    fds.push_back({listen_fd, POLLIN, 0});

    while (true) {
        int ret = poll(fds.data(), fds.size(), -1);
        if (ret < 0) {
            perror("poll failed");
            break;
        }

        for (auto& fd : fds) {
            if (fd.revents & POLLIN) {
                if (fd.fd == listen_fd) {
                    // Accept new connection
                    int new_socket = accept(listen_fd, nullptr, nullptr);
                    if (new_socket < 0) {
                        perror("accept failed");
                        continue;
                    }
                    fds.push_back({new_socket, POLLIN, 0});
                } else {
                    // Handle incoming data
                    char buffer[1024] = {0};
                    ssize_t count = read(fd.fd, buffer, 1024);
                    if (count > 0) {
                        write(fd.fd, buffer, count); // Echo back
                    } else {
                        close(fd.fd);
                        fd.fd = -1; // Mark for removal
                    }
                }
            }
        }

        // Remove closed connections
        fds.erase(std::remove_if(fds.begin(), fds.end(), [](const struct pollfd& pfd) { return pfd.fd == -1; }),
                  fds.end());
    }

    close(listen_fd);
    return 0;
}
