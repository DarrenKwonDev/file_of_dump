#include <iostream>
#include <list>

using namespace std;
int main(void) {

    list<int> l;
    list<int>::iterator i;

    l.push_back(12);  // 12
    l.push_back(23);  // 12 23
    l.push_front(10); // 10 12 23

    cout << l.back() << endl;  // 23
    cout << l.front() << endl; // 23

    i = l.insert(l.begin(), 99); // 99 10 12 23
    cout << *i << endl;          // 새로 삽입된 곳을 가리킴.

    i = l.erase(--l.end()); // 마지막 원소를 지우면 l.end()를 반환함.
    --i;
    cout << *i << endl; // 12.

    return 0;
}
