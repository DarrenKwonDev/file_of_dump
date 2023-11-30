#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void test(const vector<int>& v, int& tot) {
    for (auto value : v) {
        tot += value;
    }
}

int main(void) {

    vector<int> list(100, 1);
    int tot = 0;

    // C++에서는 람다 함수가 참조하는 변수에 대한 스레드 안전성을 보장하기 위해 추가적인 처리가 필요합니다.
    // ref?
    // const reference가 아닌 reference를 전달할면 ref로 한 번 묶어야 한다.
    std::thread thread([](const vector<int>& v, int& tot) {
        for (auto value : v) {
            tot += value;
        }
    },
                       list, ref(tot));

    thread.join();
    cout << tot << endl;

    return 0;
}