#include <iostream>
#include <vector>

using namespace std;

class B;

class A {
public:
private:
    shared_ptr<B> mB;
};

class B {
public:
private:
    // 객체가 소유한 다른 객체를 weak_ptr로 참조하게 하면 순환 참조가 발생하지 않음
    weak_ptr<A> mA;
};

int main(void) {

    return 0;
}