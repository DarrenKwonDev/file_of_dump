#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> v;
    v.reserve(10); // cap 10개 잡아주세요
    cout << v.capacity() << endl;
    cout << v.size() << endl;
    cout << *v.begin() << endl; // 없음. 왜? 초기화 자체가 안됨. for based loop나 v[i] = 2 꼴의 할당이 안 됨.

    vector<int> v2(10);            // cap10개에 0으로 채워주세요
    cout << v2.capacity() << endl; // 10
    cout << v2.size() << endl;     // 10

    vector<int> v3(5, 2);          // cap 5개고 원소 2로 채워주세요
    cout << v3.capacity() << endl; // 5
    cout << v3.size() << endl;     // 5
}