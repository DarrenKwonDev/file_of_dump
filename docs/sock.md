<!-- toc -->

-   [socket programming](#socket-programming)
    -   [socket](#socket)
        -   [client socket과 server socket의 차이점](#client-socket과-server-socket의-차이점)
    -   [window, linux 상호 운용 socket](#window-linux-상호-운용-socket)
        -   [조건부 컴파일](#조건부-컴파일)
        -   [third party library](#third-party-library)
    -   [resources](#resources)

<!-- tocstop -->

# socket programming

## socket

-   socket(domain, communication type, protocol): socket 생성.

server socket method

-   bind(sockfd, sockaddr\*, socklen_t): ip, port 지정 지정해줘야 한다.
-   listen(sockfd, backlog): 소켓을 연결 가능한 상태로 변경

client socket method

-   connect(sockfd, sockaddr\*, socklen_t): 다른 소켓에게 연결 요청

데이터 교환 및 종료
accept(): 연결 요청에 대한 수락
read(), write()
close()

### client socket과 server socket의 차이점

socket 생성 자체는 이 둘을 구분하지 않는다.
bind -> listen 함수 호출이 이어지면 server socket이고,
connect 함수 호출이 이어지면 client socket이다.

## window, linux 상호 운용 socket

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
