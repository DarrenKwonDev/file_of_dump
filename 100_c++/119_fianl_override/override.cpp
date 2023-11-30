#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    virtual void SetWeight(float weight);
    void PrintAll();
};

class Dog : public Animal {
public:
    // (1) 제대로 override 하였음. OK
    virtual void SetWeight(float weight) override;

    // (2) compile error. base class의 함수 시그니처와 맞지 않음. float을 받아야 하는데 int를 받다니.
    virtual void SetWeight(int weight) override;

    // (3) compile error. Animal의 PrintAll이 가상함수가 아니므로 override하는 것도 불가능
    void PrintAll() override;
};

int main(void) {

    return 0;
}
