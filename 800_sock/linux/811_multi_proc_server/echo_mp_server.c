
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_pid_t.h>
#include <sys/_types/_socklen_t.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFF_SIZE (1024)

void zombie_ps_cleanup(int sig);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        puts("argc should be 2");
        exit(1);
    }

    // signal handler
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = zombie_ps_cleanup;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, 0);

    // create tcp socket
    int serv_sock_fd;
    serv_sock_fd = socket(PF_INET, SOCK_STREAM, 0);

    // set server addr
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    // bind sockaddr_in into socket
    if ((bind(serv_sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) == -1) {
        puts("bind fail");
        exit(1);
    }

    // listen. backlog 5
    if ((listen(serv_sock_fd, 5)) == -1) {
        puts("listen fail");
        exit(1);
    }

    while (1) {
        
        // accept client
        int conn_sock_fd;
        struct sockaddr_in client_addr;
        socklen_t client_addr_sz = sizeof(client_addr);
        conn_sock_fd = accept(serv_sock_fd, (struct sockaddr*)&client_addr, &client_addr_sz);
        if (conn_sock_fd == -1) {
            puts("accept fail");
            continue;
        }
        printf("connect client: ip %s, port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));


        // buff 
        char* buff[BUFF_SIZE];
        int read_sz;

        // create child ps
        pid_t pid = fork();
        if (pid == -1) { // fail
            puts("child ps creation fail");
            // server를 종료시키지 않아야 한다.
            // tcp conn을 맺은 sock만 닫고, 다른 conn을 처리하도록 continue 처리
            close(conn_sock_fd);
            continue;
        } else if (pid == 0) { // child ps
            
            // 자식 소켓이므로 서버 소켓을 닫자.
            // 소켓은 운영체제의 소유이며 fd만 복사되었음.
            // 이 경우 모든 fd가 close 되어야만 소켓이 닫히기 때문에 리소스 정리를 위해서라도 사용하지 않는 fd는 close하자.
            close(serv_sock_fd);

            // echoing
            while ((read_sz = read(conn_sock_fd, buff, BUFF_SIZE)) != 0) {
                write(conn_sock_fd, buff, read_sz);
            }

            close(conn_sock_fd);
            puts("client disconnect");
            return 0;

        } else { // parent ps
            
            // conn sock fd는 child ps에서 복사해갔고, 
            // parent ps에서는 해당 소켓에 대한 관심이 없어졌으니 close하는 것이 좋다.
            close(conn_sock_fd);
        }
    }
    close(serv_sock_fd);

    return 0;
}


void zombie_ps_cleanup(int sig) {
    if (sig == SIGCHLD) {
        pid_t pid;
        int status;
        pid = waitpid(-1, &status, WNOHANG);
        printf("close child ps %d\n", pid);
    }
}