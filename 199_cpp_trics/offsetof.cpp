#include <iostream>

using namespace std;

struct Person {
    int ID;
    float scores;
    char name[6];
};

int main(void) {
    cout << offsetof(Person, ID) << endl;
    cout << offsetof(Person, scores) << endl;
    cout << offsetof(Person, name) << endl;

    return 0;
}
