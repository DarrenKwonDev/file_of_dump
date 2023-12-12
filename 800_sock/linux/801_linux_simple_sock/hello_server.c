#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error_handling(char* message);

int main(int argc, char* argv[]) {
    int serv_sock_fd;
    int clnt_sock;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    if (argc != 2) {
        exit(1);
    }

    // PF_INET: create a socket in the IPv4 Internet namespace
    // SOCK_STREAM: style is like a pipe. It operates over a connection with a particular remote socket and transmits data reliably as a stream of bytes.
    // socket method return file descriptor
    serv_sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock_fd == -1) {
        error_handling("serv sock creation failed");
    }

    // set sock addr
    memset(&serv_addr, 0, sizeof(serv_addr)); // sin_zero를 채우기 위해.
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // server의 ip를 자동으로 할당함.
    serv_addr.sin_port = htons(atoi(argv[1]));

    // socket binding(id, port, ...)
    if (
        bind(serv_sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("bind error");
    }

    // listen
    if (listen(serv_sock_fd, 5) == -1) {
        error_handling("listen error");
    }

    // accept client
    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(
        serv_sock_fd, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1) {
        error_handling("accept error");
    }

    // send data to clint sock.
    char msg[] = "test yo";
    write(clnt_sock, msg, sizeof(msg));

    // clean up
    close(clnt_sock);
    close(serv_sock_fd);
    return 0;
}

void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}