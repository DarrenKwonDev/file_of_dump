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
    weak_ptr<A> mA;
};

int main(void) {

    return 0;
}