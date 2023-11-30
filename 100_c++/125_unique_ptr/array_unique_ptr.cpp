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
    // [Vector, Vector, Vector ... Vector] 생성하기.
    // C+11 에서 unique_ptr만 존재할 때
    unique_ptr<Vector[]> vectors(new Vector[20]);

    // C++14 이후 make_unique 사용
    unique_ptr<Vector[]> vectors2 = make_unique<Vector[]>(20);

    return 0;
}
