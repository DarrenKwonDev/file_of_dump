#include "customArr.h"
#include <iostream>

using namespace std;

int main() {
    CustomArr<int>* arr = new CustomArr<int>();

    cout << arr->GetSize() << endl;
    arr->Add(1);
    cout << arr->GetSize() << endl;

    delete arr;
    return 0;
}