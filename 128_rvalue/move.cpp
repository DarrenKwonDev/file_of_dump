#include <iostream>
#include <vector>

using namespace std;

int main() {

    int num = 10;
    int&& rTen = 10;
    int&& rNum = move(num); // move는 lvalue를 rvalue로 바꿔줌.

    cout << rTen << endl;
    cout << rNum << endl;

    return 0;
}
