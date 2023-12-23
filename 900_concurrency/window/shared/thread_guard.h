#pragma once
#include <thread>


// RAII style thread guard
class thread_guard {
public:
    explicit thread_guard(std::thread& _t) : mThread(_t) {
    }

    virtual ~thread_guard() {
        if (mThread.joinable()) {
            mThread.join();
        }
    }

    thread_guard(thread_guard& const) = delete; // 복사 생성자 삭제
    thread_guard& operator=(thread_guard& const) = delete; // 복사 대입 연산자 삭제

private:
    std::thread& mThread;
};