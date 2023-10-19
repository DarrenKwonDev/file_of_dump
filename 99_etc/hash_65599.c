#include <stdio.h>

size_t hash_65599(const char* string, size_t len) {
    size_t i;
    size_t hash;

    hash = 0;
    for (i = 0; i < len; i++) {
        hash = 65599 * hash + string[i];
    }
    return hash ^ (hash >> 16);
}

int main() {
    printf("%zu\n", hash_65599("Hello", 5));
    return 0;
}
