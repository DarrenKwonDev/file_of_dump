
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/_endian.h>
#include <sys/_types/_socklen_t.h>
#include <sys/select.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE (1024)

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("argc should be 2\n");
        exit(1);
    }
    char buff[BUFF_SIZE];

    // create sock
    int serv_sock_fd;
    if ((serv_sock_fd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
        printf("sock creation fail");
        exit(1);
    }


    // set serv addr
    struct sockaddr_in serv_addr;
    socklen_t serv_addr_len = sizeof(serv_addr);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    // bind
    if ((bind(serv_sock_fd, (struct sockaddr*)&serv_addr, serv_addr_len)) == -1) {
        printf("bind fail\n");
        exit(1);
    }

    // listen
    if ((listen(serv_sock_fd, 5)) == -1) {
        printf("listen fail\n");
        exit(1);
    }

    // set read sets
    // server 소켓도 연결시켜야 함. 서버도 클라이언트 요청 받아줘야 하니까 select 관리 하에 있어야 함.
    fd_set read_set, cpy_read_set;
    FD_ZERO(&read_set);
    FD_SET(serv_sock_fd, &read_set); 
    int fd_max = serv_sock_fd;

    // iterative select server
    while (1) {
        cpy_read_set = read_set;
        
        struct timeval timeout;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        // fd의 갯수는 곧 가장 큰 fd의 숫자 + 1이다. 배열이 0부터 시작하므로.
        int fd_num = select(fd_max + 1, &cpy_read_set, 0, 0, &timeout);
        if (fd_num == -1) {
            printf("select fail");
            break;
        }
        if (fd_num == 0) {
            continue;
        }

        for (int i = 0; i < fd_max + 1; i++)
        {
            // 변화가 있는 소켓.
            if (FD_ISSET(i, &cpy_read_set)) {
                // 서버 소켓에 변동 사항이 있었다는 것은, 클라이언트 측에서 연결 요청을 했다는 것을 의미
                if (i == serv_sock_fd) {
                    struct sockaddr_in client_addr;
                    socklen_t client_addr_sz = sizeof(client_addr);
                    int conn_sock_fd;

                    if ((conn_sock_fd =accept(serv_sock_fd, (struct sockaddr *)&client_addr, &client_addr_sz)) == -1) {
                        printf("fail accept\n");
                        continue;
                    }

                    FD_SET(conn_sock_fd, &read_set);

                    if (fd_max < conn_sock_fd) {
                        fd_max = conn_sock_fd;
                    }

                    printf("client connected fd : %d\n", conn_sock_fd);
                } else { // msg 읽기
                    int read_sz = read(i, buff, BUFF_SIZE);
                    if (read_sz <= 0) {
                        FD_CLR(i, &read_set);
                        close(i);
                        printf("closed client %d\n", i);
                    } else {
                        // echo
                        write(i, buff, read_sz);
                    }
                }
                
            }
        }

    }

    close(serv_sock_fd);
    
    return 0;
}