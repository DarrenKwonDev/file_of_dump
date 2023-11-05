#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    vector<int> v;
    vector<int>::iterator i; // 개념상 포인터
    v.reserve(3);

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
    }

    i = v.end(); // 마지막 원소를 가리키지 않음.

    return 0;
}
