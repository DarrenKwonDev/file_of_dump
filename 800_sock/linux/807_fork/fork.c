#include <stdio.h>
#include <unistd.h>

int globalVar = 0;

int main(int argc, char* argv[]) {

    pid_t pid;
    int localVar = 20;
    localVar += 5;
    globalVar++;

    pid = fork(); // create child process, 이전의 모든 메모리값을 복사해 감.
    if (pid == 0) {
        // child process의 경우
        globalVar += 2;
        localVar += 2;
    } else {
        // parent process의 경우
        printf("child pid is %d\n", pid);
        globalVar -= 2;
        localVar -= 2;
    }

    if (pid == 0) {
        printf("child process gloval : %d local :%d\n", globalVar, localVar);
    } else {
        printf("main process gloval : %d local :%d\n", globalVar, localVar);
    }

    return 0;
}