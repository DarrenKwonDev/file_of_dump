#include "hello.h"
#include <iostream>

/*
    namespace
    함수, 클래스 등의 이름 충돌 방지.
*/
namespace another_hello {
void printHelloWorld() {
    std::cout << "actually, goodbye cruel world" << std::endl;
}
} // namespace another_hello

// using은 네임스페이스 생략을 의미
// 단, namespace 본 목적인 이름 충돌 방지는 없어짐.
using namespace std;

int main(void) {
    hello::printHelloWorld();
    another_hello::printHelloWorld();

    cout << "wow";

    return 0;
}