#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    
    unsigned long ip = htonl(inet_addr(argv[1]));
    if (ip == INADDR_NONE) {
        printf("error");
    } else {
        printf("%lx\n", ip); // 100007f
    }

    // 직접 struct에 넣지 않고 inet_aton을 사용할 수 있다.
    struct sockaddr_in sock_addr;
    inet_aton("127.0.0.1", &sock_addr.sin_addr);

    // inet_ntoa로 sockaddr_in의 ip를 char*로 변환할 수 있다.
    char* str_ptr = inet_ntoa(sock_addr.sin_addr);

    return 0;
}