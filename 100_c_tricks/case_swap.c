#include <stdio.h>

int main() {
    char str[101];
    scanf("%s", str);
    for (int i = 0; str[i]; ++i) {
        // 'A'의 ASCII 코드는 65이고 'a'의 ASCII 코드는 97입니다. 따라서 'A'와 'a'를 XOR 연산하면 32가 됩니다. 이것은 대문자와 소문자 사이의 ASCII 코드 차이를 나타내므로 대소문자를 바꾸는 데 사용됩니다.
        // XOR 비트 연산자(^)를 사용하여 ASCII 문자 코드를 토글(Toggle)하는 방식으로 대소문자를 바꿉니다.
        str[i] ^= 32;
    }
    printf("%s", str);
}
