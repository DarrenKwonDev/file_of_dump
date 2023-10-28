#include <stdio.h>

int main(void) {
    char buff[100];
    sprintf(buff, "hello");

    printf("%s", buff);
    return 0;
}