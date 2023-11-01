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

    int getAge() const {
        return mAge;
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

    void Mew() {
    }

private:
    string mName;
};

int main(void) {

    Cat* cat = new Cat(5, "pepe"); // 부모 생성자 먼저 호출 후 자식 생성자 호출.

    cout << cat->getAge() << endl; // 자식이 부모 멤버 변수와 메서드 접근 가능.

    delete cat; // 자식 소멸자 먼저 호출 후 베이스 소멸자 호출.

    return 0;
}