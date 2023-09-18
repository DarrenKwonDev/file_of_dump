#include <stdio.h>

/*
    C에는 bool이 없다. 
    C99에서나 들어온다. false면 0 아니면 true로 간주한다.
    관습적으로 1이 true
*/

int is_student(const int id) {
    if (id < 10) {
        return 1; // true
    } else {
        return 0; // false
    }
}

int main(void) {
    printf(is_student(3) ? "true" : "false");
    return 0;
}