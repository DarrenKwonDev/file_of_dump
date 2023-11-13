#include <iostream>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
};

int main(void) {
    unordered_map<string, int> uMap;

    uMap.insert(pair<string, int>("juju", 1));
    uMap.insert(pair<string, int>("lala", 2));

    // structured_binding
    for (const auto& [name, num] : uMap) {
        cout << name << " " << num << "\n";
    }

    // structured_binding
    Point p = {1, 2};
    auto [x, y] = p;
    cout << x << y;

    return 0;
}