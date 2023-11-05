#include <iostream>
#include <vector>

using namespace std;

class Car {
public:
    Car(string name) : mWheel(4), mName(name) {}
    virtual ~Car() {}

    int GetWheelCnt() {
        return mWheel;
    }
    void SetWheelCnt(int newCnt) {
        mWheel = newCnt;
    }
    string GetName() {
        return mName;
    }
    void SetName(string newName) {
        mName = newName;
    }

private:
    int mWheel;
    string mName;
};

int main(void) {
    // 권고되는 방식이 아님.
    // 객체를 직접 저장하는 방식의 벡터는 재할당시에 부하가 크다.
    vector<Car> cars;
    cars.reserve(4);

    cars.push_back(Car("a"));
    cars.push_back(Car("b"));
    cars.push_back(Car("c"));
    cars.push_back(Car("d"));

    cout << cars.capacity() << endl;
    cout << sizeof(cars) << endl;

    vector<Car>::iterator iter = cars.begin();
    while (iter != cars.end()) {
        if (iter->GetName() == "b") {
            // b를 지우고 그 자리를 지칭하는 포인터로 다시 변경해야 함.
            // erase를 사용하는 일반 패턴임.
            iter = cars.erase(iter);
        } else {
            iter++;
        }
    }

    // iterator의 copy본은 mutate해도 원본이 바뀌지 않음.
    // 원본 변경을 원한다면 i->SetWheelCnt()를 호출하여야 함.
    for (vector<Car>::iterator i = cars.begin(); i != cars.end(); i++) {
        Car tmpCar = *i; // *i의 카피본.

        if (tmpCar.GetWheelCnt() == 4) {
            tmpCar.SetWheelCnt(2);
        }
    }

    // 그대로 4임.
    cout << cars[0].GetWheelCnt() << endl;

    return 0;
}
