#include <iostream>
#include <vector>

using namespace std;

class Vector {
public:
    Vector() : mX(0), mY(0){};
    Vector(int x, int y) : mX(x), mY(y){};
    virtual ~Vector() {}

    // 복사 생성(copy constructor)
    Vector(const Vector& other) : mX(other.mX), mY(other.mY){};

    // 이동 생성(move constructor)
    // 왜 const를 뺐나? 이동 생성한 다음에 rvalue는 사라져야 함.
    Vector(Vector&& rOther) : mX(rOther.mX), mY(rOther.mY) {

        // rOther는 제거되어야 함.
        rOther.mX = 0;
        rOther.mY = 0;
    };

    // 이동 대입 연산.
    // 마찬가지로 대입 후 rvalue는 사라져야 함.
    Vector& operator=(Vector&& rOther) {
        if (this != &rOther) { // 자기 자신에게 대입하는지 검사
            // 현재 객체의 내용을 이동 대상 객체(rOther)의 내용으로 이동
            mX = rOther.mX;
            mY = rOther.mY;
            // 이동 대상 객체(rOther)를 빈 상태로 만듭니다.
            rOther.mX = 0;
            rOther.mY = 0;
        }
        return *this;
    }

    int GetX() {
        return mX;
    }

private:
    int mX;
    int mY;
};

int main() {
    Vector v(2, 3);

    // rvalue를 넘겨 이동 생성.
    // rvalue이니 호출 이후이므로 v는 아무 것도 없어져야 함.
    // v가 없도록 이동 생성자 로직 내부에서 잘 작성해야 함.
    Vector moveCopied(move(v));

    cout << moveCopied.GetX() << endl;
    cout << v.GetX() << endl;

    // 이동 대입 생성.
    Vector v2(2, 3);
    Vector moveAssignedCopied = move(v2);

    cout << moveAssignedCopied.GetX() << endl;
    cout << v2.GetX() << endl;

    return 0;
}
