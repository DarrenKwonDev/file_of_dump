#include <iostream>
#include <thread>
#include "../shared/thread_guard.h"

void foo() {
    std::cout << "foo func called\n";
}

void error_thrown_func() {
    throw std::runtime_error("he he runtime error for testing thread guard\n");
}

int main(void) {

    std::thread t1(foo);
    
    // bad case
    //error_thrown_func(); // runtime ������ �߻��ϸ鼭 join���� ���ϰ� ���μ����� �׳� �����. thread�� ���� cleanup�� �̷����� ����.
    //t1.join(); // useless

    // use guard. better.
    thread_guard tg1(t1);
    error_thrown_func(); // runtime ������ �߻��ؼ� main �Լ����� ������� �� �� thread guard�� ���� thread joining�� ��.
    
    return 0;
}