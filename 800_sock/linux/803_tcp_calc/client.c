#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define INT_SIZE (4)

int main(int argc, char* argv[]) {
    const int BUF_SIZE = 1024;
    char msg[BUF_SIZE];
    int result, op_cnt, i;

    if (argc != 3) {
        printf("arg is not match\n");
        exit(1);
    }

    int sock_fd;
    if ((sock_fd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation error");
        exit(1);
    }
    
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect error");
        exit(1);
    }

    printf("connect. server -> %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    printf("input op cnt: ");
    scanf("%d", &op_cnt);
    msg[0] = (char)op_cnt;
    
    for(i=0; i < op_cnt; i++) {
        printf("op %d: ", i);
        scanf("%d", (int*)&msg[1 + i * INT_SIZE]);
    }
    fgetc(stdin); // remove newline char

    printf("input operator");
    scanf("%c", &msg[1 + op_cnt * INT_SIZE]);
    msg[2 + op_cnt * INT_SIZE] = '\0';

    // [3, 1, 2, 3, +] 꼴로 msg가 구성됨.
    write(sock_fd, msg, 2 + op_cnt * INT_SIZE);

    // 4 byte를 읽기로 application protocol 합의.
    read(sock_fd, &result, INT_SIZE);

    printf("res is %d\n", result);

    close(sock_fd);

    return 0;
}