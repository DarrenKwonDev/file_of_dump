#include <iostream>
#include <stack>

using namespace std;
int main(void) {

    stack<int> s;

    s.push(1);
    s.push(14);
    s.push(32);
    s.push(99); // 1 14 32 99

    cout << s.top() << endl;

    if (!s.empty()) {
        s.pop();
    }

    cout << s.top() << endl;

    return 0;
}
