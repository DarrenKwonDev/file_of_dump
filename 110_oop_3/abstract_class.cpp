#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    Animal() {}
    virtual ~Animal() {}

    // 순수 가상 함수 (구현이 없는 virtual 함수)
    // 자식 클래스에서 반드시 구현되어야 함.
    virtual void Speak() = 0;

private:
    int mAge;
};

class Cat : public Animal {
public:
    virtual ~Cat() {}

    void Speak() {}

private:
    char* mName;
};

int main(void) {
    // 추상 클래스를 통해 개체를 만들 수 없음.
    // Animal* ani = new Animal(); // compile error. 추상 클래스이므로 초기화 못 함.
    // Animal animal; // compile error.

    // 단, 포인터나 참조형으론 사용 가능.
    Animal* cat = new Cat();
    Animal& cat_ref = *cat;

    return 0;
}