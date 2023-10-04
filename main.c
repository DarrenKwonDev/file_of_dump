#include <stdio.h>

typedef struct {
    int x;
    int y;
} point_t;

int main() {
    point_t p;
    FILE* stream;
    char buffer[1024];
    p.x = 1;
    p.y = 2;

    stream = fopen("test.txt", "r");
    if (stream == NULL) {
        perror("fopen");
        return 1;
    }

    while (1) {
        if (fgets(buffer, sizeof(buffer), stream) == NULL) {
            break;
            return 1;
        }
        printf("%s\n", buffer);
    }

    return 0;
}
