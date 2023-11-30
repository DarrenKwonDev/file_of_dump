#include <stdio.h>

/*
    sizeof
    sizeof -> byte로 크기를 반환한다.
    sizeof는 함수가 아니다. '연산자'이다.
    컴파일 타임에 크기를 찾음. 즉, 런타임 시점에 돌지 않음. 따라서 컴파일할 시점에서 알 수 없다면
    size_t형을 반환한다. (본인 환경 하에는 typedef unsigned long size_t)
    그러나 웬만하면 unsigned int(2^32 - 1)이 일반적.
*/

/*
    size_t
    _t 접두사 = typedef
    일반적으로 size_t의 최고값을 잘못된 색인을 표현하는 반환 값으로 사용하곤 함.
*/
int main(void)
{
    // size_of
    int a = 3;
    size_t b = sizeof(a);
    printf("%lu", sizeof(a));

    return 0;
}
