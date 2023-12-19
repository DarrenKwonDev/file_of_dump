#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_socklen_t.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) {

    int sock_type;
    socklen_t optlen = sizeof(sock_type);

    int tcp_sock_fd, udp_sock_fd;
    tcp_sock_fd = socket(PF_INET, SOCK_STREAM, 0); // SOCK_STREAM = 1
    udp_sock_fd = socket(PF_INET, SOCK_DGRAM, 0); // SOCK_DGRAM = 2

    // https://pubs.opengroup.org/onlinepubs/7908799/xns/getsockopt.html
    int state;
    state = getsockopt(tcp_sock_fd, SOL_SOCKET, SO_TYPE, (void*)&sock_type, &optlen);
    if (state == -1) {
        exit(1);
    }
    printf("tcp_sock_fd SO_TYPE : %d\n", sock_type);

    state = getsockopt(udp_sock_fd, SOL_SOCKET, SO_TYPE, (void*)&sock_type, &optlen);
    if (state == -1) {
        exit(1);
    }
    printf("udp_sock_fd SO_TYPE : %d\n", sock_type);




    return 0;
}