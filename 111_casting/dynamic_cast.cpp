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
    Cat(int age) : mAge(age) {}
    virtual ~Cat() {}

private:
    int mAge;
};

class Dog : public Animal {
public:
    Dog() : mHouseName("white house") {}
    virtual ~Dog() {}
    void printHouseName() {
        cout << this->mHouseName;
    }

private:
    string mHouseName;
};

int main(void) {

    Animal* pet = new Cat(3);

    // 잘못된 형 변환도 컴파일은 됨.
    // 단, 가지고 있지 않은 멤버 변수, 함수 호출은 UB.
    Dog* my_dog = static_cast<Dog*>(pet);
    my_dog->printHouseName();

    // 잘못된 형 변환에 NULL을 반환함.
    Dog* my_dog2 = dynamic_cast<Dog*>(pet);
    cout << boolalpha << (my_dog2 == NULL); // true

    // 만약 형 변환이 성공했다면 바르게 호출 가능함.
    if (my_dog2) {
        my_dog2->printHouseName();
    }

    return 0;
}
