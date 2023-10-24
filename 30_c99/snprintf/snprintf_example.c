#include <stdio.h>

int main() {
    char buff[20];
    int age = 20;
    snprintf(buff, 5, "%ddjghjwow", age);
    printf("%s", buff);
    return 0;
}
