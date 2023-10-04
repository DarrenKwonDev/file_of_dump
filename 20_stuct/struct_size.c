#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} date_t;

date_t get_d_day() {
    date_t d_day;
    d_day.day = 6;
    d_day.month = 6;
    d_day.year = 2055;

    return d_day;
}

int main() {
    date_t date;
    date_t dates[] = {
        {1, 1, 2020},
        get_d_day(),
    };

    printf("%zu\n", sizeof(date_t)); // 12 (4 * 3)

    for (size_t i = 0; i < 2; i++) {
        date = dates[i];
        printf("Date: %d.%d.%d\n", date.day, date.month, date.year);
    }

    return 0;
}
