#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void error_handling(char* message);

int main(int argc, char* argv[]) {
    int fd;
    char msg[] = "go go";
    fd = open("./hello.txt", O_CREAT | O_WRONLY | O_TRUNC);
    if (fd == -1) {
        error_handling("fd fail");
        exit(1);
    }

    write(fd, msg, sizeof(msg) - 1);
    close(fd);

    return 0;
}

void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}