#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void printMsg(const string& msg) {
    static mutex sMutex;

    // RAII style의 mutex wrapper.
    // scope를 벗어나면 자동으로 unlock이 됨.
    // std::scoped_lock<mutex> lock(sMutex); // C++17
    // std::lock_guard<mutex> locks(sMutex);  // C++11

    // 이 스코프 벗어나면 lock이 해제됨.
    // lock을 함수 전체에 걸면 느리니까 scope를 별도로 만들어서 scoped_lock을 거는 기법이 자주 사용됨.
    {
        std::scoped_lock<mutex> lock(sMutex); // C++17
        cout << msg << endl;
    }
}

int main() {

    std::thread thread(printMsg, "child thread");

    printMsg("main thread");

    if (thread.joinable()) {
        thread.join();
    }

    return 0;
}
