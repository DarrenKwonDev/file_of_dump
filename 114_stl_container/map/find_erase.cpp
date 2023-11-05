#include <iostream>
#include <map>

using namespace std;

int main(void) {

    map<string, int> simpleMap;
    simpleMap.insert(pair<string, int>("a", 1));
    simpleMap.insert(pair<string, int>("b", 2));
    simpleMap.insert(pair<string, int>("c", 3));

    // https://en.cppreference.com/w/cpp/container/map/find
    map<string, int>::iterator it = simpleMap.find("a");

    // If no such element is found, past-the-end (see end()) iterator is returned.
    if (it != simpleMap.end()) {
        it->second = 3;
    }

    cout << simpleMap["a"] << endl; // mutate

    // https://en.cppreference.com/w/cpp/container/map/erase
    // 타 stl container와 같이, 지운 후 해당 자리에 채워진 원소를 가리키는 포인터 반환.
    map<string, int>::iterator i = simpleMap.erase(it);
    cout << i->first << endl; // b

    simpleMap.erase("b"); // key 값을 주어 삭제도 가능.

    return 0;
}
