#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    void Speak(){};
};

class Dog : public Animal {
    // only virtual member functions can be marked 'final'
    virtual void Speak() final {
        cout << "bowwow" << endl;
    }
};

class Doge : public Dog {
    // error: declaration of 'Speak' overrides a 'final' function
    void Speak(){};
};

int main(void) {

    return 0;
}
