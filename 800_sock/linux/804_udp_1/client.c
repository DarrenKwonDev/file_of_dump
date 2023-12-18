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
    char msg[BUF_SIZE];

    if (argc != 3) {
        printf("argc should be 3");
        exit(1);
    }

    int client_sock_fd;
    if ((client_sock_fd = socket(PF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket create fail");
        exit(1);
    }
    printf("socket creation success\n");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    struct sockaddr_in from_addr;
    socklen_t from_addr_size = sizeof(from_addr);
    int read_sz;
    
    while (1) {
        printf("msg is: ");
        fgets(msg, sizeof(msg), stdin);

        // 보내자 
        sendto(client_sock_fd, msg, strlen(msg), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        
        // recvfrom 이후 데이터를 보낸 from_addr가 채워짐.
        read_sz = recvfrom(client_sock_fd, msg, BUF_SIZE, 0, (struct sockaddr*)&from_addr, &from_addr_size);
        msg[read_sz] = '\0';
        printf("msg from server %s", msg);
    }

    close(client_sock_fd);

    return 0;
}