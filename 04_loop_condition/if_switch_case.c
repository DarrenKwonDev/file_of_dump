#include <stdio.h>

int main(void)
{
    int num1 = -3;

    // if block
    if (num1 > 0) {
        printf("num1 is positive number\n");
    } else if (num1 < 0) {
        printf("num1 is negative number\n");
    } else {
        printf("num1 is zero\n");
    }

    // switch block
    enum day {
        MONDAY,
        TUESDAY,
        WEDNESDAY,
    };
    enum day today = MONDAY;

    switch (today) { // switch expression에는 '정수'만 올 수 있음.
    case MONDAY:
        printf("Today is Monday\n");
        break; // fall-through 방지. 필수임.
    case TUESDAY:
        printf("Today is Tuesday\n");
        break;
    default:
        break;
    }

    return 0;
}