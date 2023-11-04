#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    vector<int> v;
    v.reserve(3);

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[2] = 500; // mutable.
    // operator[](size_t n)의 반환은 '참조'(reference)를 반환함.

    cout << v[2] << endl;

    return 0;
}
