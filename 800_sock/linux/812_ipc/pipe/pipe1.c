#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFF_SIZE (30)

int main(int argc, char* argv[]) {

    int fds[2];
    char str[] = "who are you?";
    char buff[BUFF_SIZE];
    pid_t pid;

    // https://pubs.opengroup.org/onlinepubs/009604599/functions/pipe.html
    if (pipe(fds) == -1) {
        puts("pipe fail");
        exit(1);
    }
    // 하나의 fds는 부모, 자식 양 쪽으로 찢어서 사용한다.
    int recv_pipe_fd = fds[0];
    int send_pipe_fd = fds[1];

    pid = fork();
    if (pid == 0) {
        // 자식 프로세스의 경우. write만 할 것이므로
        close(recv_pipe_fd);
        write(send_pipe_fd, str, strlen(str));
    } else {
        // 부모 프로세스의 경우 read만 할 것이므로
        close(send_pipe_fd);
        read(recv_pipe_fd, buff, BUFF_SIZE);
        printf("recv : %s\n", buff);
    }

    return 0;
}