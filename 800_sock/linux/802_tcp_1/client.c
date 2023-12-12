#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error_handling(char* message);

int main(int argc, char* argv[]) {

    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len;

    if (argc != 3) {
        printf("arg is not match");
        exit(1);
    }

    // create socket
    if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation error");
        exit(1);
    }

    // set sock addr
    // port는 16비트이므로 short형이다. 그래서 hton(s)
    // ip는 32비트이므로 long형이다. 그래서 hton(l)
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // inet_addr: 문자열을 네트워크 바이트 순서의 정수로 변환
    serv_addr.sin_port = htons(atoi(argv[2])); // atoi: 문자열을 정수로 변환

    // client sock이 지정한 곳으로 connect 요청
    // connect가 반환되었다고 연결된 것이 아님. 서버 측의 backlog queue에 담겼음을 의미함.
    // 클라이언트 즉의 ip, port를 connect 호출 시 커널에서 자동으로 임의 선택함.
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect error");
        exit(1);
    }

    // read data
    str_len = read(sock, message, sizeof(message) - 1);
    if (str_len == -1) {
        error_handling("read error");
    }

    printf("msg from server %s \n", message);
    close(sock);

    return 0;
}

void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}