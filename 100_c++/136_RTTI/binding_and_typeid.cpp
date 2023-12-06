
#include <iostream>

class Base {
public:
    virtual ~Base(){};
    virtual void Method() {
        std::cout << "base" << std::endl;
    };
};

class Derived : public Base {
public:
    void Method() override {
        std::cout << "derived" << std::endl;
    }
};

int main(void) {
    // 정적 바인딩으론 Base이나 동적 바인딩은 Derived
    // Base의 Method가 virtual이라서 런타임 시에 VTable 찾아서 출력함.
    Base* child = new Derived();

    std::cout << typeid(Derived).name() << std::endl; // 7Derived
    std::cout << typeid(Base).name() << std::endl;    // 4Base

    std::cout << typeid(child).name() << std::endl; // P4Base (4Based의 포인터 타입)

    // 동적 바인딩된 실질 타입의 출력
    std::cout << typeid(*child).name() << std::endl;                  // 7Derived
    std::cout << int(typeid(Derived) == typeid(*child)) << std::endl; // 1

    delete child;

    return 0;
}