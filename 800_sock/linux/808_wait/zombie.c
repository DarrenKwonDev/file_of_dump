#include <stdio.h>
#include <unistd.h>

#define CHILD (0)

int main(int argc, char* argv[]) {
    pid_t pid = fork();

    if (pid == CHILD) {
        puts("i'm child proc");
    } else {
        printf("child ps pid is %d\n", pid);

        // parent ps가 30초간 살아 있음. 
        // 그 사이에 child ps는 종료되었으나 부모가 끝내지 않았으므로 zombie 상태. (Z+)
        // child ps의 역할은 끝났으나 컴퓨팅 리소스를 잡아 먹고 있음.
        sleep(30); 
    }

    if (pid == CHILD) {
        puts("end child process");
    } else {
        puts("end parents process");
    }

    return 0;
}