#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} date_t;

void increase_year(date_t* date) {

    // 연산자 우선 순위에 의해 역참조를 먼저 해야함을 괄호로 표현해야 함.
    // *date.year는 *(date.year)를 의미하게 됨.
    // (*date).year++;

    // 위 방식을 간편하게 표현하기 위해 -> 연산자를 사용할 수 있음.
    // 구조체의 포인터 변수를 사용할 때는 -> 연산자를 사용하는 것이 좋다.
    // 화살표를 권장한다.
    date->year + 1;
}

int main() {
    date_t date;
    date.day = 1;
    date.month = 3;
    date.year = 2020;

    increase_year(&date);

    printf("Date: %d.%d.%d\n", date.day, date.month, date.year);

    return 0;
}
