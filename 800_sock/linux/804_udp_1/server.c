#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_socklen_t.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE (30)

int main(int argc, char* argv[]) {
    char msg[BUF_SIZE];

    if (argc != 2) {
        printf("argc should be 2");
        exit(1);
    }
    printf("argc check pass\n");
    
    // datagram 방식. (udp)
    int serv_sock_fd;
    if ((serv_sock_fd = socket(PF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket create fail");
        exit(1);
    }

    printf("sock create success\n");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind fail");
        exit(1);
    }

    printf("bind success\n");

    struct sockaddr_in client_addr;
    socklen_t client_addr_size;
    int read_sz;

    // listen, accept 하는 코드가 존재하지 않음
    while (1) {
        client_addr_size = sizeof(client_addr);

        printf("recv standby");
        
        // 데이터를 받은 후 client_addr와 client_addr_size가 채워짐
        read_sz = recvfrom(serv_sock_fd, msg, BUF_SIZE, 0, (struct sockaddr*)&client_addr, &client_addr_size);

        printf("recv success. sz are %d\n", read_sz);
        
        sendto(serv_sock_fd, msg, read_sz, 0, (struct sockaddr*)&client_addr, client_addr_size);
    }
    
    close(serv_sock_fd);

    return 0;
}