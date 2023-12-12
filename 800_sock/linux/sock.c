#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void) {
    
    /*
        socket(protocol family, 전송 방식, protocol)

        protocol family
        - PF_INET : ipv4
        - PF_INET6 : ipv6
        - PF_LOCAL : local communication
        - PF_PACKET : low level packet interface
        - PF_IPX : ipx

        전송 방식
        - SOCK_STREAM : tcp. 연결 지향, 순차적이고 신뢰성이 있으며 boundary 미존재
        - SOCK_DGRAM : udp. 비연결, 순서 없고 신뢰성이 없으며 boundary 존재
        - SOCK_RAW : raw socket
        - SOCK_SEQPACKET : sequenced packet
        - SOCK_RDM : reliable datagram layer

        protocol
        protocol family 안에서 데이터 전송방식이 동일한 프로토콜이 둘 이상 존재하는 경우가 있음.
        이런 경우에는 protocol을 통해 구분함.
    */
    int sockFd = socket(PF_INET, SOCK_STREAM, 0);

    close(sockFd);

    return 0;
}