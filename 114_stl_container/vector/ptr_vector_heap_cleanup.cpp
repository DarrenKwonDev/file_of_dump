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
    vector<Car*> cars;
    cars.reserve(4);

    // new로 선언하였으니 Car*를 반환하며 데이터는 heap에 저장됨.
    cars.push_back(new Car("a"));
    cars.push_back(new Car("b"));

    // 여기서, cars vector를 삭제하고 싶다고 생각하자.
    // 동적으로 할당된 힙을 수작업으로 종료해줘야 한다. clear 메서드는 사용한 힙을 자동 정리하지 않는다.
    for (vector<Car*>::iterator i = cars.begin(); i < cars.end(); i++) {
        // 삭제!
        delete *i;
    }

    cars.clear();

    return 0;
}
