#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    Person(int age, string name) : mAge(age), mName(name) {}
    virtual ~Person() {}

    static int GetAuthLevel() {
        return mDefaultAuthLevel;
    }

    // 정적 함수.
    static void UpgradeDefaultAuthLevel() {

        mDefaultAuthLevel++;
        // static 함수에서는 일반 멤버 변수에 접근 불가. 적절 멤버 변수만 접근 가능.
        // mAge++; // error: invalid use of member 'mAge' in static member function
    }

    void IncAge() {
        mAge++;
    }

private:
    static int mDefaultAuthLevel;

    int mAge;
    string mName;
};

// 정적(static) 멤버 변수를 선언할 때는 클래스 외부에서 해당 변수를 초기화해야 합니다.
int Person::mDefaultAuthLevel = 1;

int main(void) {
    Person* p1 = new Person(20, "pepe");
    Person* p2 = new Person(25, "huhu");

    cout << Person::GetAuthLevel() << endl;
    Person::UpgradeDefaultAuthLevel();

    // object도 클래스의 static 변수나 함수를 호출할 수 있다.
    cout << p1->GetAuthLevel() << endl;

    return 0;
}
