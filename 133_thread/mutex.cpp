#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void printMsg(const string& msg) {
    static mutex sMutex;

    // console 자원도 공유 자원이므로
    // 동일 스레드에서 두 번 lock 하면 deadlock이 발생함. 꼭 그렇게 해야 한다면 std::recursive_mutex를 사용할 것.
    sMutex.lock();
    cout << msg << endl;

    // unlock을 안한다?
    // unlock 하기 전에 return해서 함수를 나가버린다?
    // 계속 lock이 걸려 있어 문제 발생.
    sMutex.unlock();
}

int main() {

    std::thread thread(printMsg, "child thread");

    printMsg("main thread");

    if (thread.joinable()) {
        thread.join();
    }

    return 0;
}
