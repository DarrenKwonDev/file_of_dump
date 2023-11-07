#include <stdio.h>
#include <string.h>

#define ALPHABET_LEN 26

void caesarShift(char* text, int shift) {
    int length = strlen(text);
    for (int i = 0; i < length; ++i) {
        // 대문자 알파벳에 대해서만 시프트 적용
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + shift) % ALPHABET_LEN) + 'A';
        }
    }
}

int main() {
    char text[] = "TNJUI";
    int shift = 25;

    printf("원본 텍스트: %s\n", text);

    // Caesar Shift 암호화 적용
    caesarShift(text, shift);

    printf("Caesar Shift 암호화 결과: %s\n", text);

    return 0;
}