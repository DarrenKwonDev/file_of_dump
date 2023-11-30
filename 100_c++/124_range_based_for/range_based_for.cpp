#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void) {
    unordered_map<string, int> uMap;
    uMap["a"] = 1;
    uMap["b"] = 2;
    uMap["c"] = 3;

    // 참조로 순회
    for (auto& kv : uMap) {
        cout << kv.first << " " << kv.second << endl;
    }

    // 값으로 순회
    for (auto kv : uMap) {
        cout << kv.first << " " << kv.second << endl;
    }

    return 0;
}
