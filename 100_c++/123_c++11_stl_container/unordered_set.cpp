#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
    unordered_set<int> uSet;
    uSet.reserve(7);

    cout << uSet.bucket_count() << endl;

    uSet.insert(10);
    uSet.insert(3);
    uSet.insert(8);

    for (auto it = uSet.begin(); it != uSet.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
