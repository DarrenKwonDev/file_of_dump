#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main(void) {

    std::thread childThread(
        [](const string& msg, const int& num) {
            cout << "wait n secs" << endl;
            std::this_thread::sleep_for(chrono::seconds(num));
            // std::this_thread::yield();
            cout << msg << endl;
        },
        "yup", 2);

    cout << "main thread" << endl;

    if (childThread.joinable()) {
        childThread.join();
    }

    return 0;
}
