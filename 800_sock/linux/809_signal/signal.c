
#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>

void timeout(int sig) {
    if (sig == SIGALRM) {
        puts("timeout.");
    }
    alarm(2); // set alarm after 2 sec again.
}

void keycontrol(int sig) {
    if (sig == SIGINT) {
        puts("ctrl + c pressed");
    }
}

void closeps(int sig) {
    if (sig == SIGTERM) {
        puts("bye bye cruel world");
        exit(0);
    }
}

int main(int argc, char* argv[]) {
    int i;
    pid_t pid = getpid();
    printf("pid is %d\n", pid);

    // signal이 발생하면, blocking되어 있는 프로세스를 깨운다.
    // 따라서 
    signal(SIGALRM, timeout);
    signal(SIGINT, keycontrol);
    signal(SIGTERM, closeps);
    alarm(2);

    for (i = 0; i < 1000; i++)
    {
        puts("wait...\n");


        // 수면 시간이 다해서 일어나지 않으면 0이 아닌 다른 값을 반환함.
        unsigned int is_early_wake = sleep(3000); // pure blocking
        
        // 운영 체제는 해당 프로세스를 "수면(sleeping)" 상태로 표시하고 CPU 자원을 다른 프로세스에 할당합니다
        // Signal이 발생하면, 남은 수면 시간을 무시하고 다음으로 진행됨.
        if (is_early_wake > 0) {
            puts("early wake");
        }
    }

    return 0;
}