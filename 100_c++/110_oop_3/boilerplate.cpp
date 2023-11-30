#include <bits/stdc++.h>
using namespace std;

/*
    무슨 내용이 있는 건 아니고
    작성한 코드 보관용.
*/

class Animal {
public:
    Animal() : mAge(0){};
    Animal(int age) : mAge(age){};
    virtual ~Animal() {}

    virtual void Speak() const {}
    virtual void Move() {}

private:
    int mAge;
};

class Cat : public Animal {
public:
    Cat(int age, string name) : Animal(age), mName(name) {}
    virtual ~Cat() {}

    void Speak() const {}

private:
    string mName;
};

int main(void) {

    Cat* cat = new Cat(5, "pepe");
    Animal* yourCat = new Cat(7, "juju");

    delete cat;
    delete yourCat;

    return 0;
}