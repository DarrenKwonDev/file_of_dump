#include <locale.h>
#include <stdio.h>
#include <uchar.h>

int main(void) {
    printf("__STDC_VERSION__ : %d\n", __STDC_VERSION__);

    printf("is utf-16 available: %d\n", __STDC_UTF_16__);
    printf("is utf-32 available: %d\n", __STDC_UTF_32__);

    // 로케일 설정 (UTF-8 인코딩을 사용하는 로케일)
    setlocale(LC_ALL, "en_US.UTF-8");

    char16_t a = u"\u00E9";     // 소문자 u에 유의
    char32_t b = U"\U0001F600"; // 대문자 U에 유의

    printf("utf-16 sizeof a : %d\n", sizeof(a)); // 2
    printf("utf-32 sizeof b : %d\n", sizeof(b)); // 4

    /*
      mb(멀티바이트)가 기본이므로 utf16, utf32의 출력을 위해서는 멀티 바이트로
      변환 필요.
      특이하게, 한 문자씩 변환이 됨.
      c16rtomb (c16 r to mb) \
      c32rtomb (c32 r to mb) \
      mbrtoc16 (mb r to c16) \
      mbrtoc32 (mb r to c32) \
    */
    char16_t utf16_str[] = u"안녕하세요선생님";
    mbstate_t state = {
        0,
    };
    char buff[32];
    char* p = buff;

    for (size_t i = 0; i < 8; ++i) {
        size_t num_bytes = c16rtomb(p, utf16_str[i], &state);

        // 다 읽었거나 실패시 c16rtomb가 -1 반환
        if ((size_t)-1 == num_bytes) {
            break;
        }
        p += num_bytes;
    }

    *p = '\0'; // 종료 후 null char 추가

    printf("%s", buff);

    return 0;
}