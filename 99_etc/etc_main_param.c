#include <stdio.h>

int main(int argc, const char* argv[]) {
    /*
        argc는 들어온 인자의 수
        ./a.out a.text b.text와 같이 호출하면 3.

        argv는 들어온 인자의 배열
        ./a.out a.text b.text와 같이 호출하면 ["./a.out", "a.text", "b.text"]
    */

    printf("argc: %d\n", argc);
    for (size_t i = 0; i < argc; i++) {
        printf("argv[%zu]: %s\n", i, argv[i]);
    }

    return 0;
}
