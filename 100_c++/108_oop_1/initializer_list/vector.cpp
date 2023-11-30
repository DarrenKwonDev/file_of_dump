#include "vector.h"
#include <iostream>

using namespace std;

Vec::Vec() : mX(0), mY(0) {
    cout << "Vec init " << mX << mY << endl;
}

Vec::Vec(int x, int y) : mX(x), mY(y) {
    cout << "Vec init " << mX << mY << endl;
}

Vec::~Vec() {
    cout << "destructor" << endl;
}