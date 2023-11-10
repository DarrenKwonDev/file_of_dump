#include <iostream>
#include <memory>

using namespace std;

class Vector {
public:
    Vector() = delete;
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

    // new로 선언하였으므로 heap에 할당됨. 따라서 delete를 하여야 하나...
    // unique_ptr로 인하여 자동 삭제.

    // Vector의 유니크 포인터 vec.
    // 이제 vec에 대입이나 복사는 불가능해짐.
    unique_ptr<Vector> vec(new Vector(3.14, 5.2));

    // 대입 불가
    // unique_ptr<Vector> copied = vec; // compile error.

    // 복사 불가
    // unique_ptr<Vector> copied(vec); // compile error.

    vec->Print();

    return 0;
}
