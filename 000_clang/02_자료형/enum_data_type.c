#include <stdio.h>

enum day
{
    MONDAY,  // 0
    TUESDAY, // 1
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

int main(void)
{
    // 둘 다 된다. enum의 장점이 C에서는 정수의 그루핑을 통한 가독성 향상 정도밖에 없음. 타입 안전성은 없음.
    enum day d = 0; // enum enum_type 변수명 = enum_type의 멤버로 선언함.
    enum day d_2 = TUESDAY;

    printf("%d, %d", d, d_2);
    return 0;
}