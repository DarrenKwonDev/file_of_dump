
#include <stdio.h>
#include <sys/signal.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig) {
    if (sig == SIGALRM) {
        puts("timeout.");
    }
    alarm(2); // set alarm after 2 sec again.
}

int main(int argc, char* argv[]) {
    int i;
    pid_t pid = getpid();
    printf("pid is %d\n", pid);

    /*
        struct  sigaction {
            union __sigaction_u __sigaction_u;   signal handler 
            sigset_t sa_mask;                signal mask to apply 
            int     sa_flags;                see signal options below 
        };
    */
    struct sigaction act;
    act.sa_handler = timeout; // #define sa_handler      __sigaction_u.__sa_handler
    sigemptyset(&act.sa_mask); // sa_mask 를 0으로 초기화.
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, 0); // sig handler

    alarm(2);

    for (i = 0; i < 1000; i++) {
        puts("wait...\n");

        unsigned int is_early_wake = sleep(3000);
        
        if (is_early_wake > 0) {
            puts("early wake\n");
        }
    }



    return 0;
}