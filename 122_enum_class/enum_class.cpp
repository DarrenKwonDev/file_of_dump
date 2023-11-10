#include <iostream>

using namespace std;

// eMyEnum의 원소는 uint8_t 형으로 표현할 수 있다.
// 즉, 255 까지만 할당 가능하며 그 이상의 숫자는 표현할 수 없음.
enum class eMyEnum : uint8_t {
    Test1,
    Test2,
    Test3,
};

enum class eAlphabetEnum {
    A,
    B,
    C
};

int main(void) {
    eMyEnum a = eMyEnum::Test1;
    eAlphabetEnum b = eAlphabetEnum::A;

    // enum에선 가능했지만 enum class에선 불가능합니다.
    // enum타입으로 초기화 해야 합니다.
    // int b = eAlphabetEnum::A;

    // enum에선 가능했지만 enum class에선 불가능합니다.
    // int로 암시적 캐스팅이 되면 참이겠지만 enum class에선 타입 검사도 됩니다.
    // if (a == b) {
    //     cout << "should not printed";
    // }

    return 0;
}
