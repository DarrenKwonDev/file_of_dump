#include <iostream>
#include <pthread.h>
#include <thread>

using namespace std;

void test(const string& str) {
    cout << str << endl;
}

int main(void) {

    thread thread(test, "child thread");

    thread.detach();
    // thread 스레드는 백그라운드에서 계속 실행 중
    // thread 스레드가 종료되기를 기다리지 않음 (join 불가)

    // detach된 thread를 join할 수 없다.
    // thread.join(); // error

    // joinable 체크후 실행할 것.
    // std::thread 객체가
    // 1.아직 다른 스레드와 결합(join)되지 않았고,
    // 2.detach되지도 않았으며
    // 3. 스레드 실행이 아직 종료되지 않은 경우
    // true를 반환
    if (thread.joinable()) {
        thread.join();
    }

    return 0;
}