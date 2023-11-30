#include <bits/stdc++.h>
using namespace std;

class Faculty {
public:
    Faculty() { cout << "faculty constructor" << endl; }
    virtual ~Faculty() { cout << "faculty destroy" << endl; }

    void Speak(){};

private:
};

class Student {
public:
    Student() { cout << "student constructor" << endl; }
    virtual ~Student() { cout << "student destroy" << endl; }

    void Speak(){};

private:
};

class TA : public Faculty,
           public Student {
public:
    TA() { cout << "ta constructor" << endl; }
    virtual ~TA() { cout << "ta destroy" << endl; }

private:
};

int main(void) {
    TA* ta = new TA(); // 상속 받은 순서대로 생성자 호출

    ta->Faculty::Speak(); // 두 base class중 어느 함수를 호출해야 하는가에 대해서 명시해야 함.

    delete ta; // 역순으로 소멸자 호출.
    return 0;
}