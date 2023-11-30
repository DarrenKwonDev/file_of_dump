#include "vector.h"
#include <bits/stdc++.h>

using namespace std;

class Person {
public:
    Person(const string name, const int age) : mName(name), mAge(age) {
        cout << "construct" << endl;
    };
    ~Person() {
        cout << "destruct" << endl;
    };

private:
    int mAge;
    string mName;
};

int main(void) {

    Person* a = new Person("john", 30);

    delete a; // heap에 할당된 것만 delete가능

    return 0;
}