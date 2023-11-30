#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    Animal() : mAge(0){};
    Animal(int age) : mAge(age) {
        cout << "animal constructor" << endl;
    };
    ~Animal() {
        cout << "animal deleted" << endl;
    }

    int GetAge() const {
        return mAge;
    };
    void Speak() {
        cout << "speak" << endl;
    }

    // 실제 함수가 아님. 자식 함수에 의해 override됨.
    // 런타임에 실체를 찾아 실행되게끔 하라.
    virtual void Move() {
        cout << "virtual function not called" << endl;
    };

private:
    int mAge;
};

// Animal을 public 상속.
class Cat : public Animal {
public:
    // 명시적이든 암시적이든 베이스 클래스의 생성자가 먼저 호출 됨.
    Cat(int age, string name) : Animal(age), mName(name) {
        cout << "cat constructor" << endl;
    }
    ~Cat() {
        cout << "cat deleted" << endl;
    }

    void Speak() {
        cout << "mew" << endl;
    }

    void Move() {
        cout << "sneaky move" << endl;
    }

private:
    string mName;
};

int main(void) {

    Cat* cat = new Cat(5, "pepe"); // 부모 생성자 먼저 호출 후 자식 생성자 호출.
    Animal* yourCat = new Cat(7, "juju");

    cout << cat->GetAge() << endl; // 자식이 부모 멤버 변수와 메서드 접근 가능.

    // overriding. 선언된 자료형에 따라 호출됨. (정적 바인딩)
    cat->Speak();     // cat의 Speak이 호출됨
    yourCat->Speak(); // animal의 Speak이 호출됨.

    // virtual function이 구현되어 override되어 호출됨. (동적 바인딩)
    cat->Move();
    yourCat->Move();

    delete cat; // 자식 소멸자 먼저 호출 후 베이스 소멸자 호출.

    return 0;
}