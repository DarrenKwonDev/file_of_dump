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

    cout << v.use_count() << endl; // 1 (강한 참조는 1개니)

    cout << weakV.use_count() << endl;

    // https://en.cppreference.com/w/cpp/memory/weak_ptr/lock
    // lock : creates a shared_ptr that manages the referenced object
    // lock is used to ensure validity of the pointer
    shared_ptr<Vector> strongV = weakV.lock();

    cout << weakV.expired() << endl;      // false. 아직 유효하므로.
    cout << (strongV == nullptr) << endl; // false. 유효하지 않으면 nullptr를 반환함.

    strongV->Print();
    cout << strongV.use_count() << endl; // 2 (결국 Vector 객체 강한 참조 2개 있으니까.)

    return 0;
}