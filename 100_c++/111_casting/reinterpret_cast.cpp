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
    Animal* cat = new Cat();

    // 이게 왜 됨?
    // reinterpret_cast는 위험하다.
    int* weird = reinterpret_cast<int*>(cat);

    // 음수를 unsigned int로 캐스팅하니 값이 망가짐.
    // signed int의 경우 -10을 비트 패턴으로 보이면
    // 1111 1111 1111 1111 1111 1111 1111 0110
    // unsigned int로 캐스팅하면
    // 위 비트패턴을 유지하면서 맨 앞의 비트가 음/양이 아닌 숫자로 변환됨.
    int* num = new int(-10);
    unsigned int* u_num = reinterpret_cast<unsigned int*>(num);
    cout << *u_num << endl; // 4294967266.

    return 0;
}
