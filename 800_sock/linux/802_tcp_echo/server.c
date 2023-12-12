#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE (1024)

int main(int argc, char* argv[]) {
    char* ip = 0;
    int port;
    
    if (argc == 3) {
        ip = argv[1];
        port = atoi(argv[2]);
    } else if (argc == 2) {
        port = atoi(argv[1]);
    } else {
        // err
        printf("err arg not match\n");
        exit(1);
    }

    printf("ip: %s, port: %d\n", (ip != 0) ? ip : "INADDR_ANY", port);
    
    int serv_sock_fd;
    if ((serv_sock_fd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
        printf("err socket create\n");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr)); // sin_zero를 채우기 위해.
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = (ip != 0) ? inet_addr(ip) : htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    if (bind(serv_sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Bind failed");
        exit(1);
    }


    // 일종의 hyperparam이라 어느 정도가 적당한지는 실험을 통해 알아야 함.
    // 5 backlog queue. 즉, 클라이언트 연결 요청을 5개 까지 홀드할 수 있음.
    if ((listen(serv_sock_fd, 5)) == -1) {
        // err
        perror("err listen\n");
        exit(1);
    }


    // accept로 back log에 대기 중인 클라이언트의 요청을 받아들임.
    struct sockaddr_in client_addr; // accept가 client의 정보를 담아줌.
    socklen_t client_addr_size = sizeof(client_addr);

    while (1) {
        // client_addr는 accept 호출 후 연결을 요청한 클라이언트의 주소 정보를 포함하게 됩니다
        // accept는 연결 요청을 위해 수립된 서버측 소켓을 통해 데이터를 주고 받을 수 있는 클라이언트 측 소켓을 반환합니다.
        int conn_sock_fd = accept(serv_sock_fd, (struct sockaddr*)&client_addr, &client_addr_size);
        if (conn_sock_fd == -1) {
            perror("err accept\n");
            exit(1);
        }
        
        printf("connect. client -> %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buff[BUF_SIZE];
        int str_len;
        while ((str_len = read(conn_sock_fd, buff, BUF_SIZE)) != 0) {
            printf("%s", buff);

            if (strcmp(buff, "q") == 0 || strcmp(buff, "q\n") == 0 ) {
                goto close_conn;
            }
            // 받은 그대로 반환. echo server
            write(conn_sock_fd, buff, str_len);
        }
        
        close_conn:
            close(conn_sock_fd);
    }

    close(serv_sock_fd);

    return 0;
}