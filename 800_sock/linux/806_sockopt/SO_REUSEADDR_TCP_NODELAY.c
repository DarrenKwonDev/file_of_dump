#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_socklen_t.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/tcp.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("argc should be 2");
        exit(1);
    }

    int serv_sock_fd;
    serv_sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock_fd == -1) {
        perror("sock create err");
        exit(1);
    }

    ////////////////////////////////////////
    // 먼저 연결 종료를 위해 FIN 메세지를 전송한 측은, 상대 호스트의 FIN 메세지를 받고나서 socket을 바로 소멸시키지 않는다.
    // 해당 상태를 time-wait 상태라 하는데, 마지막 전송 후 해당 패킷의 에러로 인한 재전송등의 잔업 처리를 위해 일정 시간 socket을 살려두는 것이다.
    // 일반적으론 안전한 해제를 위해서 필요하지만, 
    // SO_REUSEADDR는 time-wait 상태의 소켓을 동일한 포트로 재사용할 수 있게 만드는 옵션이다. 
    // default가 0 이라 1로 켜준 후 곧바로 서버가 재실행 가능해진다.
    int option;
    socklen_t optlen;
    option = 1;
    setsockopt(serv_sock_fd, SOL_SOCKET, SO_REUSEADDR, (void*)&option, optlen);
    ////////////////////////////////////////


    ////////////////////////////////////////
    // Nagle 알고리즘을 비활성화 합니다. 
    option = 1;
    optlen = sizeof(option);
    setsockopt(serv_sock_fd, IPPROTO_TCP, TCP_NODELAY, (void*)&option, optlen);
    ////////////////////////////////////////


    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if ((bind(serv_sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) == -1) {
        perror("bind fail");
        exit(1);
    }

    if ((listen(serv_sock_fd, 5)) == -1) {
        perror("listen fail");
        exit(1);
    }

    int conn_sock_fd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_sz = sizeof(client_addr);

    accept(conn_sock_fd, (struct sockaddr*)&client_addr, &client_addr_sz);

    const int buff_size = 30;
    char* buff[buff_size];
    int read_sz;
    while ((read_sz = read(conn_sock_fd, buff, buff_size)) != 0) {
        // simple echo
        write(conn_sock_fd, buff, read_sz);
        write(fileno(stdout), buff, read_sz); // console에서도 보이게
    }

    close(conn_sock_fd);
    close(serv_sock_fd);
    
    return 0;
}