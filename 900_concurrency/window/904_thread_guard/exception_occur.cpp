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
    //error_thrown_func(); // runtime 에러가 발생하면서 join되지 못하고 프로세스가 그냥 종료됨. thread에 대한 cleanup이 이뤄지지 않음.
    //t1.join(); // useless

    // use guard. better.
    thread_guard tg1(t1);
    error_thrown_func(); // runtime 에러가 발생해서 main 함수에서 벗어나려고 할 때 thread guard에 의해 thread joining이 됨.
    
    return 0;
}