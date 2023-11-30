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

    // 원시 포인터를 요구할 때는 get 메서드를 통해
    // unique_ptr가 소유하고 있는 원시 포인터를 받을 수 있다.
    getNakedPtr(v.get());

    // 이런 식으로.
    Vector* naked = v.get();

    return 0;
}
