#include <iostream>
#include <map>

using namespace std;
int main(void) {

    map<string, int> scores;

    // if 문에서 Lulu가 초기화 되며, 값이 0이므로 else문으로 빠짐
    if (scores["Lulu"]) {
        scores["Lulu"] = 50;
    } else {
        // operator[]는 중복 키의 경우 덮어씀.
        // 그러나 insert는 중복 키의 경우 연산을 무시함.
        scores.insert(pair<string, int>("Lulu", 100));
    }

    // 0이 출력됨.
    cout << scores["Lulu"] << endl;

    return 0;
}