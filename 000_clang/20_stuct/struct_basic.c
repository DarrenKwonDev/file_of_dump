#include <stdio.h>

struct date {
    int year;
    int month;
    int day;
};

int is_monday(struct date date) {
    int day = date.day;
    int month = date.month;
    int year = date.year;
    return 0; // omit logic
};

int main() {
    struct date date; // 자료형이 'struct date' 이다.
    date.day = 1;
    date.month = 1;
    date.year = 1900;

    is_monday(date);

    return 0;
}
