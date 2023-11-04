#include <iostream>
#include <vector>

using namespace std;

class Car {
public:
    Car() : mWheel(4) {}
    virtual ~Car() {}

    int mWheel;
};

int main(void) {
    vector<Car> cars;
    cars.reserve(3);
    cout << &cars << endl;

    cars.push_back(Car());
    cars.push_back(Car());

    cout << cars.capacity() << endl; // 3
    cout << cars.size() << endl;     // 2
    cars.shrink_to_fit();            // size에 맞게 cap을 줄여라
    cout << cars.capacity() << endl; // 2로 줄어듦

    return 0;
}
