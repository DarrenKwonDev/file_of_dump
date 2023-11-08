#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class WowSoLongClassNameItsSoClassy {
public:
    WowSoLongClassNameItsSoClassy() {}
    virtual ~WowSoLongClassNameItsSoClassy() {}
};

int main() {
    // 1. basic
    auto* p_i = new int(3);
    auto& int_ref = *p_i;

    delete p_i;

    // 2. const
    const int a = 10;
    // const int& 형으로 받아야 함.
    // auto로 지정해도 const를 이어 받아 const int& 형이 된다.
    auto& a_ref = a;
    const auto& const_a_ref = a; // 위와 같지만 이렇게 쓰는 것이 좋다.

    // 3-1. 반복자를 auto 쓰면 편함.
    vector<int> v = {1, 2, 3};
    auto i = v.begin();
    for (; i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";

    // 3-2. 이름 긴 클래스의 인스턴스. auto로 쓰면 편함.
    auto* inst = new WowSoLongClassNameItsSoClassy();
    delete inst;

    return 0;
}
