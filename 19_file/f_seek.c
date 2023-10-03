#include <stdio.h>

/*
    Hello World! 가정.
*/
int main(void) {
    FILE* stream;
    char line[256];

    stream = fopen("test.txt", "r");

    // error handle omit

    // only read 3 characters
    if (fgets(line, 4, stream) == NULL) {
        perror("fgets");
    }
    printf("%s\n", line);

    /*
        ftell
        현재 file pos indicator의 위치를 반환한다.
        https://en.cppreference.com/w/c/io/ftell
    */
    printf("%ld\n", ftell(stream));

    /*
        https://en.cppreference.com/w/c/io/fseek
        #define SEEK_SET 파일 시작
        #define SEEK_CUR 현재 파일 위치
        #define SEEK_END 파일 끝
        int fseek( FILE *stream, long offset, int origin );

        origin으로부터 offset만큼 file pos indicator를 이동시킨다.

        fseek(stream, 0, SEEK_END) 마지막으로 가기
        fseek(stream, 0, SEEK_SET) 처음으로 가기
    */
    int res = fseek(stream, 3 * sizeof(char), SEEK_CUR);
    // 현재 위치에서 3만큼 이동. 파일에는 문자만 존재한다는 가정임.
    // 그 결과 Hel까지 있던 indicator가 W까지 이동됨
    // Hello World!
    //   ^   ^

    if (res != 0) {
        perror("fseek");
    }

    // file pos indicator가 3만큼 이동한 상태부터 나머지를 읽어보자.
    while (1) {
        if (fgets(line, 256, stream) == NULL) {
            break;
        }
        printf("%s\n", line);
    }
}