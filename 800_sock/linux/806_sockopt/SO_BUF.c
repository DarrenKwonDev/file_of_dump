#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_socklen_t.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) {
    int sock_fd;
    int send_buf;
    int receive_buf;
    socklen_t tmp_sz;
    int state;

    sock_fd = socket(PF_INET, SOCK_STREAM, 0);

    // 임의로 출력 버퍼의 크기 조정 해보고 출력.
    // 단, 완벽하게 반영되지는 않고, 내부적으로 최소 버퍼 크기나 기타 사항을 고려해 엇비슷한 크기를 배정함.
    tmp_sz = sizeof(send_buf);
    send_buf = 1024 * 2;
    state = setsockopt(sock_fd, SOL_SOCKET, SO_SNDBUF, (void*)&send_buf, tmp_sz);
    state = getsockopt(sock_fd, SOL_SOCKET, SO_SNDBUF, (void*)&send_buf, &tmp_sz);
    if (state == -1) {
        exit(1);
    }
    printf("출력 버퍼 크기 %d\n", send_buf);

    tmp_sz = sizeof(receive_buf);
    state = getsockopt(sock_fd, SOL_SOCKET, SO_RCVBUF, (void*)&receive_buf, &tmp_sz);
    if (state == -1) {
        exit(1);
    }
    printf("입력 버퍼 크기 %d\n", receive_buf);

    return 0;
}