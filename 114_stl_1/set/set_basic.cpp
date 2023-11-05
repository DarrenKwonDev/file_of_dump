#include <iostream>
#include <set>

using namespace std;
int main(void) {

    set<int> s;

    s.insert(10);
    s.insert(34);
    s.insert(3);
    s.insert(9);
    s.insert(9); // 중복된 값의 삽입은 무시됨.

    // 오름차순으로 정렬되어 존재함.
    for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}
