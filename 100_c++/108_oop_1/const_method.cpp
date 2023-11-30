#include <bits/stdc++.h>

using namespace std;

class Vec {
public:
    Vec() : mX(0), mY(0){};
    Vec(int x, int y) : mX(x), mY(y){};
    ~Vec(){};

    void SetX(int x) { mX = x; };
    void SetY(int y) { mY = y; };

    // const method
    // 해당 클래스로 생성된 인스턴스 내의 멤버 변수를 바꾸지 않음을 의미.
    int GetX() const { return mX; };
    int GetY() const { return mY; };
    void Add(const Vec& other) {
        mX += other.mX;
        mY += other.mY;
    };

private:
    int mX;
    int mY;
};

int main(void) {
    Vec v(2, 5);
    Vec a(11, 7);

    cout << v.GetX() << endl;

    v.Add(a);

    cout << v.GetX() << endl;

    return 0;
}