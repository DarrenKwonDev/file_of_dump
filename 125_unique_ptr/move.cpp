#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Vector {
public:
    Vector() : mX(0), mY(0){};
    Vector(double x, double y) : mX(x), mY(y){};
    virtual ~Vector() {
        cout << "good bye" << endl;
    }

    void Print() {
        cout << "vector : " << mX << " " << mY << endl;
    }

private:
    double mX;
    double mY;
};

int main(void) {
    // unique_ptr의 소유권은 다른 unique_ptr로 옮길 수 있음
    // 단, const unique_ptr는 move할 수 없다.
    // 이전할 경우 전의 unique_ptr은 nullptr이 됨.

    unique_ptr<Vector> v = make_unique<Vector>(1.1, 2.2);

    // 소유권 이전.
    // 메모리 할당/해제가 이루어지지 않고 단순히 소유권을 옮기기만 함.
    // move는 lvalue를 rvalue로 변환하는 역할임.
    // unique_ptr를 복사 생성하면 unique의 정의와 다름. 따라서 임시적인 rvalue로 변환하는 과정이 필요하여 std::move 사용.
    unique_ptr<Vector> v2(move(v));

    cout << (v == nullptr) << endl; // true

    return 0;
}
