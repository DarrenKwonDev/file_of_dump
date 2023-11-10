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

void getNakedPtr(Vector* vec) {
    vec->Print();
}

int main(void) {

    unique_ptr<Vector> v = make_unique<Vector>(1.1, 2.2);

    // 원시 포인터를 반환. get과 달리 unique_ptr의 소유권이 이전됨.
    // 어.. 근데 그러면 그냥 옛날 원시 포인터 다루듯 다뤄야 함.
    Vector* naked = v.release();
    delete naked;

    // 소유권이 이전되었으므로 unique_ptr는 null_ptr를 가리킴.
    Vector* oh = v.get();
    cout << (oh == nullptr) << endl;

    return 0;
}
