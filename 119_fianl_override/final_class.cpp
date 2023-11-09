#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Animal {
};

// Dog은 final class이므로 Base class로 사용 불가.
class Dog final : public Animal {
};

// error: base 'Dog' is marked 'final'
class Doge : public Dog {
};

int main(void) {

    return 0;
}