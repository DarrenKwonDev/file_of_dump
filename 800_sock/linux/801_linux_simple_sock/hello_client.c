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
        printf("port is %s", argv[0]);
        exit(1);
    }

    // create socket
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket error");
    }

    // set sock addr으
    // port는 16비트이므로 short형이다. 그래서 hton(s)
    // ip는 32비트이므로 long형이다. 그래서 hton(l)
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // inet_addr: 문자열을 네트워크 바이트 순서의 정수로 변환
    serv_addr.sin_port = htons(atoi(argv[2])); // atoi: 문자열을 정수로 변환

    // client sock이 지정한 곳로 connect 요청
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("connect error");
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