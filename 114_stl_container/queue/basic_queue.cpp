#include <iostream>
#include <queue>

using namespace std;
int main(void) {

    queue<int> q;

    q.push(3);
    q.push(34);
    q.push(2);
    q.push(20);

    cout << q.size() << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;

    if (!q.empty()) {
        q.pop();
    }

    cout << q.front() << endl;

    return 0;
}
