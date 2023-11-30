#include <bits/stdc++.h>
using namespace std;

class Vector {
public:
    Vector() : mX(0), mY(0){};
    Vector(const int x, const int y) : mX(x), mY(y){};
    Vector(const Vector& other) : mX(other.mX), mY(other.mY){};
    ~Vector() {}

    // overload +
    Vector operator+(const Vector& rhs) const {
        // rhs = right hand side.
        Vector sum;
        sum.mX = mX + rhs.mX;
        sum.mY = mY + rhs.mY;
        return sum;
    }

private:
    int mX;
    int mY;
};

int main(void) {
    Vector v1(10, 20);
    Vector v2(5, 12);

    Vector sum = v1 + v2;
    Vector sum2 = v1.operator+(v2); // 위와 같음. 그러나 잘 쓰지는 않는다.

    return 0;
}