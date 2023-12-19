#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_socklen_t.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE (30)

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("argc should be 2");
        exit(1);
    }

    //프로그램이 실행될 때의 작업 디렉토리
    FILE* fp = fopen("./.clang-format", "rb");
    if (fp == NULL) {
        printf("file pointer creation fail");
        exit(1);
    }

    int serv_sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock_fd == -1) {
        printf("sock creation fail");
        exit(1);
    }

    printf("sock created\n");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if ((bind(serv_sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) == -1) {
        printf("bind fail");
        exit(1);
    }

    printf("bind successful.\n");

    if (listen(serv_sock_fd, 5) == -1) {
        printf("listen fail");
        exit(1);
    }

    int conn_sock_fd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_sz = sizeof(client_addr);
    conn_sock_fd = accept(serv_sock_fd, (struct sockaddr*)&client_addr, &client_addr_sz);

    int read_sz;
    char buff[BUF_SIZE];
    while (1) {
        // BUF_SIZE 만큼 연결된 소켓에게 전송.
        read_sz = fread((void*)buff, 1, BUF_SIZE, fp);
        if (read_sz < BUF_SIZE) { // 끝까지 다 읽었구나.
            write(conn_sock_fd, buff, read_sz);
            break;
        }
        write(conn_sock_fd, buff, BUF_SIZE);
    }

    // 전송을 마치고 half-close
    shutdown(conn_sock_fd, SHUT_WR); // 출력 스트림 닫음
    read(conn_sock_fd, buff, BUF_SIZE);
    printf("last msg from client : %s\n", buff);

    fclose(fp);
    close(conn_sock_fd);
    close(serv_sock_fd);
    return 0;
}