<!-- toc -->

-   [socket programming](#socket-programming)
    -   [socket](#socket)
        -   [socket의 생성](#socket의-생성)
        -   [socket의 주소 (sockaddr_in)](#socket의-주소-sockaddr_in)
        -   [binding (server socket)](#binding-server-socket)
        -   [listen (server socket)](#listen-server-socket)
        -   [accept](#accept)
        -   [connect (client socket)](#connect-client-socket)
        -   [데이터 교환 및 종료](#데이터-교환-및-종료)
        -   [client socket과 server socket의 flow](#client-socket과-server-socket의-flow)
    -   [theoretical background](#theoretical-background)
        -   [tcp-ip model](#tcp-ip-model)
        -   [tcp](#tcp)
        -   [UDP](#udp)
    -   [portability](#portability)
        -   [조건부 컴파일](#조건부-컴파일)
        -   [third party library](#third-party-library)
    -   [resources](#resources)

<!-- tocstop -->

# socket programming

## socket

### socket의 생성

-   socket(domain, communication type, protocol): socket 생성.

socket(protocol family, 전송 방식, protocol)

[protocol family]

-   PF_INET : ipv4
-   PF_INET6 : ipv6
-   PF_LOCAL : local communication
-   PF_PACKET : low level packet interface
-   PF_IPX : ipx

[전송 방식]

-   SOCK_STREAM : tcp. 연결 지향, 순차적이고 신뢰성이 있으며 boundary 미존재
-   SOCK_DGRAM : udp. 비연결, 순서 없고 신뢰성이 없으며 boundary 존재
-   SOCK_RAW : raw socket
-   SOCK_SEQPACKET : sequenced packet
-   SOCK_RDM : reliable datagram layer

[protocol]
protocol family 안에서 데이터 전송방식이 동일한 프로토콜이 둘 이상 존재하는 경우가 있음.  
이런 경우에는 protocol을 통해 구분함.

소켓의 생성과 동시에 입력 버퍼, 출력 버퍼가 생성됨.

### socket의 주소 (sockaddr_in)

여기서 socket의 주소라는 것은 family(주소 체계), ip, port로 이루어짐.

```cpp
struct sockaddr_in {
    __uint8_t       sin_len;
    sa_family_t     sin_family; // 주소 체계
    in_port_t       sin_port; // __uint16_t TCP/UDP 포트 번호
    struct  in_addr sin_addr; // __uint32_t struct 32비트 IP 주소
    char            sin_zero[8]; // 사용되지 않음
}
```

-   network byte order를 맞추는 것은, sockaddr_in 에서만 신경쓰면 된다.
-   sockaddr_in을 작성한 후 할당
    -   server sock에게는 bind(이 주소로 오는 건 나한테 보내),
    -   client sock에는 connect(이 주소로 연결해)

```cpp
struct sockaddr_in serv_addr;

// set sock addr
memset(&serv_addr, 0, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = htonl(inet_addr(argv[1])); // network byte order를 맞출 것
serv_addr.sin_port = htons(atoi(argv[2])); // network byte order를 맞출 것
```

### binding (server socket)

-   bind(sockfd, sockaddr\*, socklen_t): ip, port 지정 지정해줘야 한다.

### listen (server socket)

-   listen(sockfd, backlog): 소켓을 연결 가능한 상태로 변경

### accept

int accept(int, struct sockaddr* restrict, socklen_t* restrict)

연결 요청에 대한 수락.
sockaddr에 연결을 요청한 client의 주소가 담김.
반환값으로 서버측의 connection 용 socket이 생성되어 반환됨.

backlog queue의 연결 요청을 하나 꺼내서 연결을 수락하고, 해당 클라이언트와 소통할 수 있는 소켓 하나를 반환 함.

### connect (client socket)

int connect(int, const struct sockaddr\*, socklen_t)

sockaddr로 연결 요청.
connect 함수가 반환되었다고 연결된 것이 아님. 서버 측의 backlog queue에 담겼음을 의미함.

UDP socket(DGRAM)의 경우에는 기본적으로 unconnected 소켓이라서 connect를 하지 않아도 데이터를 보낼 수 있음.
만약 connect를 한다면 connected 소켓이 되어서 read, write를 사용할 수 있게 됨.

### 데이터 교환 및 종료

read(), write(), recvfrom(), sendto()
close()

### client socket과 server socket의 flow

-   tcp 기준

server sock flow : socket 생성 -> bind -> listen -> accept(conn socket 생성) -> read/write -> close

client sock flow : socket 생성 -> connect(커널에 의한 자동 ip, port 지정) -> read/write -> close

-   udp 기준

수락을 허용하는 과정이 아니라 곧바로 각 소켓 간의 소통이 이뤄지므로 서버와 클라이언트란 구분이 모호한 편이다.

socket 생성 -> bind -> recvfrom/sendto -> close

하나의 소켓만 존재하면 되며, tcp와 달리 연결 상태를 유지하지 않으므로 데이터 전송시 주소를 명시해야 함. 대신, listen, accept가 없음.

sendto 시점에 socket의 ip, port 지정이 안 되어 있으면 자동 할당됨.

## theoretical background

### tcp-ip model

application
tcp/udp(transport) : 도착한 호스트 내에서 열린 소켓으로 패킷을 전달하는 역할은 tcp/udp
ip(network) : 특정 호스트에서 다른 호스트까지 패킷을 보내는 역할은 ip
link : 물리계층

-   port는 응용 프로그램을 구분하기 위한 번호가 아니라, 통신을 위해 소켓에 부여되는 번호다. 응용 프로그램이 소켓을 하나 물고 있다고 오해한다. 한 응용 프로그램이 여러 소켓을 물고 있을 수도 있다.

### tcp

    스트림 지향: TCP는 전송되는 데이터를 개별적인 메시지로 취급하지 않고 연속적인 바이트 스트림으로 다룹니다. 이는 데이터가 전송 순서대로 정확하게 도착한다는 것을 의미합니다.

    데이터 간 경계 없음 (No Boundary): TCP는 데이터를 바이트 단위로 전송하며, 각 바이트 사이에 명시적인 경계나 구분이 없습니다. 예를 들어, 응용 프로그램이 TCP를 통해 500바이트를 전송하면, 이 데이터는 도착지에서 500바이트 묶음으로 수신될 수도 있고, 여러 작은 조각으로 분할되어 수신될 수도 있습니다. TCP는 이러한 조각들을 원래 순서대로 재조립합니다. -> 응용 계층에서의 경계 설정이 필요함, 즉, `application protocol을 설정해야 함. 특정 문자가 등장하면 stream을 한 번 끊는 등의 방식으로 클라-서버 간의 규약을 정해야 함.`

### UDP

    UDP (User Datagram Protocol)는 TCP와 달리 비연결 지향적이고, 메시지 지향적인 프로토콜.

    비연결 지향 (Connectionless): UDP는 연결을 설정하거나 종료하는 과정이 없습니다. 즉, 데이터를 보내기 전에 통신 상대방과의 연결을 미리 설정할 필요가 없습니다. 이는 UDP가 간단한 네트워크 요청에 적합하게 만들며, TCP에 비해 오버헤드가 적습니다.
    -> listen, accept가 없음.

    메시지 지향 (Message-Oriented): UDP는 데이터를 독립적인 메시지 단위로 처리합니다. 각 UDP 패킷(또는 '데이터그램'이라고 불림)은 독립적으로 전송되며, 각 패킷은 명확한 경계를 가지고 있습니다. 이는 수신자가 각각의 메시지를 별도로 인식할 수 있게 합니다.

    신뢰성과 순서 보장 부재: UDP는 TCP와 달리 데이터 전송의 신뢰성이나 순서를 보장하지 않습니다. 패킷은 손실될 수 있고, 순서대로 도착하지 않을 수 있습니다. 이 때문에, 신뢰성이 중요하지 않거나 손실이나 순서 변경에 민감하지 않은 애플리케이션에서 UDP가 사용됩니다.

    속도와 효율성: 연결 설정과 관리가 필요 없으며, 오버헤드가 적기 때문에 UDP는 TCP보다 빠르고 효율적입니다. 이는 실시간 애플리케이션(예: 비디오 스트리밍, 온라인 게임)에서 유리합니다.

    오류 검사 기능: UDP 헤더에는 체크섬이 포함되어 있어 데이터가 손상되었는지 간단히 검사할 수 있습니다. 그러나 손상된 패킷의 복구나 재전송은 제공하지 않습니다.

    헤더 크기: UDP의 헤더 크기는 TCP보다 작습니다. 이는 전송되는 데이터에 대한 추가적인 오버헤드를 줄여줍니다.

## portability

### 조건부 컴파일

아래와 같은 꼴로 작성하는 방식.

```c
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
    #else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#endif
```

### third party library

Boost.Asio

## resources

-   [The GNU C Library(old ver) socket](https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_chapter/libc_16.html#SEC300)

-   [sys/socket.h](https://pubs.opengroup.org/onlinepubs/7908799/xns/syssocket.h.html)

-   [BeeJ's Guide to Network Programming.](https://questions.icon-library.com/)
