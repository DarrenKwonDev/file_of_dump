#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    Animal() {}
    virtual ~Animal() {}

private:
};

class Cat : public Animal {
public:
    Cat() {}
    virtual ~Cat() {}

private:
};

void Foo(const Animal* ptr) {
    // const Animal* -> Animal*로 변환됨.
    Animal* animal = const_cast<Animal*>(ptr);
}

int main(void) {

    return 0;
}
