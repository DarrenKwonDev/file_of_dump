typedef struct {
    int year;
    int month;
    int day;
} date_t;

int main() {
    date_t date = {2023, 10, 4}; // 실수할 여지가 많음. 순서를 바꾸면 안됨.

    // 이 방식이 실수를 줄이는 방식.
    date.day = 4;
    date.month = 10;
    date.year = 2023;
    printf("%d년 %d월 %d일\n", date.year, date.month, date.day);

    return 0;
}
