#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    Animal() : mAge(0){};
    Animal(int age) : mAge(age){};

    // 가상 소멸자
    virtual ~Animal() {
        cout << "animal deleted" << endl;
    }

private:
    int mAge;
};

class Cat : public Animal {
public:
    Cat(int age, string name) : Animal(age), mName(name) {
    }

    // 부모가 가상 소멸자면 자식도 가상 소멸자로 변환되지만 명시적으로 적는 것이 좋다.
    virtual ~Cat() {
        cout << "cat deleted" << endl;
    }

private:
    string mName;
};

int main(void) {

    Cat* cat = new Cat(5, "pepe");
    Animal* yourCat = new Cat(7, "juju");

    // 자식 소멸자 먼저 호출 후 베이스 소멸자 호출.
    // 정적 바인딩이어도 문제 없음.
    delete cat;

    // virtual deconstructor가 없다면 Animal의 소멸자만 호출됨. 왜? 정적 바인딩이라서.
    delete yourCat;

    return 0;
}