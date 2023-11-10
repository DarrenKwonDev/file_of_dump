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
    shared_ptr<Vector> v = make_shared<Vector>(1.1, 2.2);
    weak_ptr<Vector> weakV = v;

    // weakV가 유효한 객체를 가리키고 있을까? 검증.

    /*
    expired:
    checks whether the referenced object was already deleted
    (public member function)

    lock:
    creates a shared_ptr that manages the referenced object
    */

    // 1. nullptr 여부로 확인하기 (OK)
    shared_ptr<Vector> shared = weakV.lock();
    if (shared == nullptr) {
    };

    // 2. 만료 여부로 확인하기 (NO)
    // expired() 메서드는 신뢰할 수 없음.
    // multi threading 환경에서 expired()가 false를 반환했는데도
    // 그 사이 다른 스레드에서 referenced object를 지웠을 수 있음.
    weakV.expired();

    return 0;
}