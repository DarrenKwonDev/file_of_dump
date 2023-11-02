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

int main(void) {

    // static cast와 c style은 같다.

    float a = 3.14f;
    int b = (int)a;              // c style
    int c = static_cast<int>(a); // static cast

    Animal* cat = new Cat();
    Cat* cat2 = (Cat*)cat;              // c style
    Cat* cat3 = static_cast<Cat*>(cat); // static cast

    return 0;
}
