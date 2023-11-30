#include <stdio.h>
#include <string.h>

int main(void) {
    char* map[100]; // array of char*
    char str[6] = "ahsdf";
    map[0] = str;

    printf("%p\n", map[0]);
    printf("%s\n", map[0]);
    return 0;
}