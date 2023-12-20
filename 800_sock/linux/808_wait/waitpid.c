#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define CHILD (0)

int main(int argc, char* argv[]) {
    int status;
    pid_t pid = fork();

    if (pid == CHILD) {
        sleep(1);
        return 24;
    } else {
        printf("child pid : %d\n", pid);

        while (!waitpid(pid, &status, WNOHANG)) {
            printf("no blocking. print before 3 secs\n");
        }

        if (WIFEXITED(status)) {
            printf("child exit code : %d", WEXITSTATUS(status));
        }
    }

    return 0;
}