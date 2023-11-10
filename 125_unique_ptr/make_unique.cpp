#include <iostream>
#include <memory>
#include <vector>

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

    // make_unique 함수는 힙에 할당됨.
    unique_ptr<Vector> vec = make_unique<Vector>(1.1, 2.2);

    vec->Print();

    return 0;
}
