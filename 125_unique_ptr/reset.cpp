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

    unique_ptr<Vector> v = make_unique<Vector>(1.1, 2.2);

    // 소유하던 힙에 있던 원시 포인터는 지워지고 다시 할당
    v.reset(new Vector(5.5, 5.5));

    // 힙에 있던 내용 지우고 nullptr를 할당
    // v = nullptr; 와 같음.
    v.reset();

    return 0;
}
