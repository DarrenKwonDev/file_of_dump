

#include <signal.h>
#include <stdio.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <unistd.h>

void handle_child(int sig) {
    if (sig == SIGCHLD) {
        int status;

        // 성공시 종료된 ps의 pid반환.
        // 특정 pid가 아닌 -1을 전달함으로써 임의의 자식 프로세스 종료를 처리함.
        pid_t id = waitpid(-1, &status, WNOHANG); // non blocking
        if (WIFEXITED(status)) {
            printf("remove ps id : %d\n", id);
            printf("child send : %d\n", WEXITSTATUS(status));
        }
    }
}

int main(int argc, char* argv[]) {
    pid_t pid = 0;

    // signal handling
    struct sigaction act;
    act.sa_handler = handle_child;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, 0);

    pid = fork();
    if (pid == 0) {
        puts("child ps");
        sleep(3);
        return 12; // trigger SIGCHLD
    } else {
        printf("first child ps pid : %d\n", pid);
        pid = fork();
        if (pid == 0) {
            puts("another child ps");
            sleep(5);
            return 20; // trigger SIGCHLD
        } else {
            printf("second child ps pid : %d\n", pid);
            pid_t main_pid = getpid();
            printf("main ps pid : %d\n", main_pid);

            int i;
            for (size_t i = 0; i < 5; i++)
            {
                puts("wait...\n");
                sleep(2);
            }
            
        }
    }


    return 0;
}