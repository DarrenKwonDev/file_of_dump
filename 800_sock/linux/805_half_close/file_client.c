#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_endian.h>
#include <sys/_types/_socklen_t.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE (30)

int main(int argc, char* argv[]) {
    
    if (argc != 3) {
        printf("argc should be 3");
        exit(1);
    }

    FILE* fp = fopen("./recv", "wb");

    int client_sock_fd;
    client_sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (client_sock_fd == -1) {
        printf("socket creation error");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if ((connect(client_sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) == -1) {
        printf("connect fail");
        exit(1);
    }

    int read_sz;
    char* buff[BUF_SIZE];
    while ((read_sz = read(client_sock_fd, buff, BUF_SIZE)) != 0)
    {
        fwrite((void *)buff, 1, read_sz, fp);
    }

    printf("receive file data successful\n");
    write(client_sock_fd, "OK", 3);
    fclose(fp);
    close(client_sock_fd);
    return 0;
}