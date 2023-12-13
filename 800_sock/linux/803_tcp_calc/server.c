#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define INT_SIZE (4)

int calc(int op_cnt, int targets[], char op) ;

int main(int argc, char* argv[]) {
    int serv_sock_fd;
    const int buff_size = 1024;
    char msg[buff_size];
    int result;

    if (argc != 2) {
        printf("arg is not match\n");
        exit(1);
    }

    serv_sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock_fd == -1) {
        perror("socket creation error");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port=htons(atoi(argv[1]));

    if (bind(serv_sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind error");
        exit(1);
    }

    if (listen(serv_sock_fd, 5) == -1) {
        perror("listen error");
        exit(1);
    }

    int conn_sock_fd;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);

    int op_cnt = 0;
    conn_sock_fd = accept(serv_sock_fd, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if (conn_sock_fd == -1) {
        perror("accept error");
        exit(1);
    }
    
    // 1 byte 앞에 op_cnt를 받기로 application protocol 합의.
    read(conn_sock_fd, &op_cnt, 1);

    printf("op_cnt: %d\n", op_cnt);

    int recv_len = 0, recv_cnt;
    while ((op_cnt * 4 + 1) > recv_len) {
        recv_cnt += read(conn_sock_fd, &msg[recv_len], buff_size - 1);
        recv_len += recv_cnt;
    }
    
    printf("recv_len: %d\n", recv_len);

    result = calc(op_cnt, (int*)&msg, msg[recv_len - 1]);
    write(conn_sock_fd, &result, INT_SIZE);
    
    close(conn_sock_fd);
    close(serv_sock_fd);
    return 0;
}

int calc(int op_cnt, int targets[], char op) {
    int result = targets[0];
    int i;
    switch (op)
    {
    case '+':
        for ( i = 1; i < op_cnt; i++)
        {
            result += targets[i];
        }
        break;
    case '-':
        for ( i = 1; i < op_cnt; i++)
        {
            result -= targets[i];
        }
        break;
    case '*':
        for ( i = 1; i < op_cnt; i++)
        {
            result *= targets[i];
        }
        break;
    default:
        break;
    }
    return result;
}