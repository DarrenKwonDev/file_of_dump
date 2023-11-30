#include <stdio.h>

/*
    scanf : stdin으로부터 읽기
    fscanf : file stream으로부터 읽기
    sscanf : c style 문자열로부터 읽기

    각각
    printf
    fprintf
    sprintf
    와 대응된다.

    secure한 버전들이 있다.
    scanf_s, fscanf_s, sscanf_s
*/

/*
    int scanf( const char *format, ... );
    int fscanf( FILE *stream, const char *format, ... );
    int sscanf( const char *buffer, const char *format, ... );
*/
int main(void) {
    int a;
    char c;
    char str[2];

    /*
        왜 메모리 주소를 넣는가?

        당연히 함수에 값 전달을 해봐야 함수 끝나면 stack 영역에 있던 값은 사라지는데(정확히는 방치되는데)
        함수 바깥의 값을 변경할면 참조형으로 전달해야하니 포인터를 전달한 것.

        이건 상식이다!

        첫 문자의 메모리 주소를 가리키는 배열은 그래서 scanf에 전달할 때 그대로 전달.
    */

    /*
        %[*][width][length]specifier
        *는 suppress assignment. 입력을 받지 않는다. 써 본적이 없다. 잘 안 쓴다고.
    */
    int k = scanf("%d %c %5s", &a, &c, str);
    printf("k: %d\n", k); // 3. 3개의 변수를 읽었다.

    printf("%d | %c | %s\n", a, c, str);

    return 0;
}