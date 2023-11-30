#include <iostream>
#include <map>

using namespace std;

int main(void) {
    map<string, int> simpleMap;

    // insert
    simpleMap.insert(pair<string, int>("a", 1));
    simpleMap.insert(pair<string, int>("b", 2));
    cout << simpleMap.size() << endl;

    // 복사 생성자를 통한 복사.
    map<string, int> copiedMap(simpleMap);
    cout << copiedMap.size() << endl;
    cout << copiedMap["a"] << endl;

    // operator[]
    simpleMap["a"] = 100;
    cout << simpleMap["a"] << endl;

    return 0;
}
