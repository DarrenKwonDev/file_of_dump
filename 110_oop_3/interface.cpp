#include <bits/stdc++.h>
using namespace std;

// cpp에서 interface는 지원하지 않음.
// 순수 가상 함수로 interface 흉내만 낼 수 있음.
class IFlyable {
public:
    virtual ~IFlyable() {} // interface도 클래스이기에 가상 소멸자는 필요.

    virtual void Fly() = 0;
};

class IWalkable {
public:
    virtual ~IWalkable() {}

    virtual void Walk() = 0;
};

// 만약 상속 받았음에도 구현하지 않으면
// unimplemented pure virtual method 에러를 받음.
// 따라서 상속 받은 interface는 구현해야 함.
class Hen : public IFlyable,
            public IWalkable {
public:
    virtual ~Hen() {}

    void Fly(){};
    void Walk(){};
};

class Cat : public IWalkable {
public:
    virtual ~Cat() {}

    void Walk(){};
};

int main(void) {

    Hen* hen = new Hen();

    return 0;
}