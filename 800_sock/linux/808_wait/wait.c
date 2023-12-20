#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHILD (0)

int main(int argc, char* argv[]) {
    int status;
    pid_t pid = fork();

    if (pid == CHILD) {
        sleep(3);
        return 3;
    } else {
        // parent ps
        printf("child pid : %d\n", pid);
        
        pid = fork();
        if (pid == CHILD) {
            exit(7);
        } else {
            printf("another child pid : %d\n", pid);

            // child ps가 2개 이므로 wait를 2번

            wait(&status); // 종료된 자식 프로세스의 exit status가 status 변수에 담기게 됨.
            if (WIFEXITED(status)) { // 정상 종료인가?
                // status는 단순 종료 코드를 담고 있는게 아닌 다양한 값의 비트 패턴이 조합되어 있음.
                // exit code만 추출하기 위해 WEXITSTATUS 매크로를 사용해야 함.
                printf("child ps 1 exit code : %d\n", WEXITSTATUS(status));
            }
            // wait를 통해 종료되었으므로 자식 ps의 리소스는 모두 회수됨.

            wait(&status); // 종료된 자식 프로세스의 exit status가 status 변수에 담기게 됨.
            if (WIFEXITED(status)) { // 정상 종료인가?
                printf("child ps 2 exit code : %d\n", WEXITSTATUS(status));
            }

            sleep(30);
        }
    }

    return 0;
}