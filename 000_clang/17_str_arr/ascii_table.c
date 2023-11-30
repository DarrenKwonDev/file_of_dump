#include <stdio.h>

/*
    ascii table
    https://www.asciitable.com/
*/

void print_ascii_table(void) {
    // ascii는 1byte로 출력 가능한 문자 (0 ~ 127)이 주어져있다.
    // 여기서 0~31과 127은 제어 문자이므로 출력은 32부터 126까지만 한다.
    const int MIN_ASCII = 32;
    const int MAX_ASCII = 126;
    const int NUM_CHARS = MAX_ASCII - MIN_ASCII + 1;
    const int NUM_COLS = 3;

    // 이런식으로 작성한 이윤 float이 int로 캐스팅되면 소수점이 제거되기 때문이다.
    // 95개의 문자를 3개로 뿌려야 한다.
    // 필요한 행은 31.6개 (95 // 3) + 1 즉, 32개가 필요하다.
    // 여기에서는 NUM_CHARS에 (NUM_COLS - 1)을 더해준다.
    // 이로써 NUM_COLS의 나머지를 '올림' 할 필요 없이 소수점을 버려도 된다.
    // 요약하자면,
    // 원래 방식 : 95개 문자를 열 갯수 3개로 나눈뒤 올림 처리한다.
    // 해당 코드 방식 : 95 + (3 - 1)을 열 갯수 3으로 나눈 뒤 소수점을 버린다.
    const int NUM_ROWS = (NUM_CHARS + (NUM_COLS - 1)) / NUM_COLS; // ceil(NUM_CHARS / NUM_COLS)과 같다.

    int r;
    int ch;

    printf("Dec Hex  Char\tDec Hex  Char\tDec Hex  Char\n");

    for (r = 0; r < NUM_ROWS - 1; ++r) {
        ch = MIN_ASCII + r;
        printf("%03d %#X %c\t", ch, ch, ch);

        ch += NUM_ROWS;
        printf("%03d %#X %c\t", ch, ch, ch);

        ch += NUM_ROWS;
        printf("%03d %#X %c\n", ch, ch, ch);
    }

    /* 마지막 줄 */
    for (ch = MIN_ASCII + r; ch <= MAX_ASCII; ch += NUM_ROWS) {
        printf("%03d %#X %c\t", ch, ch, ch);
    }
}

int main(void) {
    print_ascii_table();

    return 0;
}