#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFF_SIZE (30)

int main(int argc, char* argv[]) {

    int fds1[2]; // 부모 ps가 받거나 쓰는 경우
    int fds2[2]; // 자식 ps가 받거나 쓰는 경우

    // create pipe
    if (pipe(fds1) == -1 || pipe(fds2) == -1) {
        puts("pipe fail");
        exit(1);
    }

    // 하나의 fds는 부모, 자식 양 쪽으로 찢어서 사용한다.
    int 부모측에서_받는_fd = fds1[0];
    int 자식측에서_쓰는_fd = fds1[1];

    // 하나의 fds는 부모, 자식 양 쪽으로 찢어서 사용한다.
    int 자식측에서_받는_fd = fds2[0];
    int 부모측에서_쓰는_fd = fds2[1];

    // msg and buff
    char msg1[] = "oh no why here?";
    char msg2[] = "what have you done?";
    char buff[BUFF_SIZE];

    pid_t pid = fork();

    if (pid == 0) { // Child process

        close(부모측에서_받는_fd); 
        close(부모측에서_쓰는_fd); 

        // Write to parent
        write(자식측에서_쓰는_fd, msg1, strlen(msg1));
        close(자식측에서_쓰는_fd);

        // Read from parent
        read(자식측에서_받는_fd, buff, BUFF_SIZE);
        printf("Child received: %s\n", buff);
        close(자식측에서_받는_fd);

    } else { // Parent process
                
        close(자식측에서_쓰는_fd);
        close(자식측에서_받는_fd);

        // Read from child
        read(부모측에서_받는_fd, buff, BUFF_SIZE);
        printf("Parent received: %s\n", buff);
        close(부모측에서_받는_fd);

        // Write to child
        write(부모측에서_쓰는_fd, msg2, strlen(msg2));
        close(부모측에서_쓰는_fd);
    }


    return 0;
}