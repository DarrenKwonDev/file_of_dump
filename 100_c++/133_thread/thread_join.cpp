#include <iostream>
#include <pthread.h>
#include <thread>

using namespace std;

void test(const string& str) {
    cout << str << endl;
}

int main(void) {

    thread thread(test, "child thread");
    thread::id child_thread_id = thread.get_id();
    cout << "child thread id : " << child_thread_id << endl;

    test("main thread");
    pthread_t main_thread_id = pthread_self();
    cout << "main thread id : " << main_thread_id << endl; // <thread>에 없어서 os function 호출해야 함.

    thread.join(); // wait until thread end.

    return 0;
}