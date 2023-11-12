#include <iostream>
#include <thread>

void ThreadFunction() {
    std::cout << "스레드 실행" << std::endl;
}

int main() {
    std::thread t(ThreadFunction); // 스레드 생성

    std::thread t2 = std::move(t); // 스레드 이동

    if (t.joinable()) {
        t.join(); // 스레드 대기
    }

    if (t2.joinable()) {
        t2.join(); // 스레드 대기
    }

    return 0;
}
