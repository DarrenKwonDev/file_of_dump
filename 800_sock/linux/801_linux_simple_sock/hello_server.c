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

    /*
        family(주소 체계), ip, port로 이루어짐.
        struct sockaddr_in {
            __uint8_t       sin_len;
            sa_family_t     sin_family;
            in_port_t       sin_port;
            struct  in_addr sin_addr;
            char            sin_zero[8];
        }
    */
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    if (argc != 2) {
        printf("port is %s", argv[0]);
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
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
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