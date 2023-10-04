#include <stdio.h>

/*
    방법 1.
    struct과 typedef를 따로 정의
*/
// struct date {
//     int year;
//     int month;
//     int day;
// };
// typedef struct date date_t;

/*
    방법 2.
    struct과 typedef를 동시에 정의.
    typedef struct date 와 같이 struct의 이름을 붙여서 정의해도 됨.
    그러나 typedef를 정의햇으므로 굳이 struct의 이름은 필요하지 않으므로 생략도 가능.
*/
typedef struct {
    int year;
    int month;
    int day;
} date_t;

int is_monday(date_t date) {
    int day = date.day;
    int month = date.month;
    int year = date.year;
    return 0; // omit logic
};

int main() {

    return 0;
}
