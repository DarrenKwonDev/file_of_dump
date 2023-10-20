#include <stdio.h>

// int, char[], int
#define TUPLE_DATA       \
    PERSON(0, "Kim", 20) \
    PERSON(1, "Lee", 25) \
    PERSON(2, "Park", 30)

int main() {
    int ids[] = {
#define PERSON(id, name, age) id,
        TUPLE_DATA
#undef PERSON
    };

    const char* names[] = {
#define PERSON(id, name, age) name,
        TUPLE_DATA
#undef PERSON
    };

    int ages[] = {
#define PERSON(id, name, age) age,
        TUPLE_DATA
#undef PERSON
    };

    for (size_t i = 0; i < 3; i++) {
        printf("%d\n", ids[i]);
        printf("%s\n", names[i]);
        printf("%d\n", ages[i]);
    }

    return 0;
}
