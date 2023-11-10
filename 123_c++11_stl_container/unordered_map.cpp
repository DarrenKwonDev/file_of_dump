#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    unordered_map<string, int> uMap;
    uMap.reserve(5);

    cout << uMap.bucket_count() << endl;

    uMap.insert(pair<string, int>("a", 2));
    uMap.insert(pair<string, int>("b", 34));
    uMap.insert(pair<string, int>("c", 34));

    // hashmap이라 순서 없음.
    for (auto it = uMap.begin(); it != uMap.end(); it++) {
        cout << it->first << endl;
    }

    // bucket의 count 만큼 돌아보자.
    for (int i = 0; i < uMap.bucket_count(); i++) {
        cout << "bucket # " << i << ": ";

        for (auto it = uMap.begin(i); it != uMap.end(i); it++) {
            cout << it->first << ":" << it->second << " ";
        }

        cout << endl;
    }

    return 0;
}
