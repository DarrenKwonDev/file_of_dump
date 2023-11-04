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

    // 3으로 10개 채움
    vector<int> scores(10, 3);
    cout << scores[3] << endl;

    // Car 10개가 들어가는 공간을 잡는 것이 아니다.
    // Car 10개의 오브젝트를 생성함.
    // 만약 Car가 생성시 인자를 받는 클래스라면 에러남.
    // 애초에 잘못 설계된 느낌임. 이렇게 쓰지 말고, 공간을 미리 잡고 싶다면 reserve를 쓰라.
    vector<Car> cars(10);

    Car car = cars[0];
    cout << car.mWheel << endl;

    return 0;
}
