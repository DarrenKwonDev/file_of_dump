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

class Dog : public Animal {
public:
    Dog() {}
    virtual ~Dog() {}

    void Bark(){};

private:
    string mHouseName = "white house";
};

int main(void) {

    // 값의 경우
    float a = 3.14f;
    long long int l = static_cast<long long int>(a);

    // 개체의 경우
    // 캐스팅할 때 상속관계에 있는가만 체크하고 변환함.
    // 즉, Cat을 또 다른 Animal의 자식 클래스로 변환해도 컴파일은 됨. 런타임에 터짐.
    Animal* cat = new Cat();

    Cat* casted_cat = static_cast<Cat*>(cat); // static cast

    Dog* should_be_wrong = static_cast<Dog*>(cat); // 컴파일 되어 버림

    return 0;
}
