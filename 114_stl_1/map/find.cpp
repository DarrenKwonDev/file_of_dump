#include <iostream>
#include <map>

using namespace std;

int main(void) {

    map<string, int> simpleMap;
    simpleMap.insert(pair<string, int>("a", 1));

    // https://en.cppreference.com/w/cpp/container/map/find
    //
    map<string, int>::iterator it = simpleMap.find("a");

    // If no such element is found, past-the-end (see end()) iterator is returned.
    if (it != simpleMap.end()) {
        it->second = 3;
    }

    cout << simpleMap["a"] << endl; // mutate

    return 0;
}
