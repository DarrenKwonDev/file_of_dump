#include <iostream>
#include <vector>

using namespace std;

class Car {
public:
    Car() {}
    virtual ~Car() {}

private:
};

int main(void) {

    vector<int> scores;
    vector<Car*> cars;

    // reserve() function can be used to eliminate reallocations if the number of elements is known beforehand.
    scores.reserve(2); // capacity가 2개.
    cout << "capacity is " << scores.capacity() << endl;

    scores.push_back(10);
    scores.push_back(13);
    scores.push_back(30); // trigger reallocate. capacity가 늘어남.

    cout << "capacity is " << scores.capacity() << endl;
    cout << "size is " << scores.size() << endl;

    for (auto k : scores) {
        cout << k << endl;
    }

    return 0;
}
