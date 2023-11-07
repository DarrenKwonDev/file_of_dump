#include "fixedVector.h"
#include <iostream>

using namespace std;

int main(void) {
    FixedVector<int, 5>* fv = new FixedVector<int, 5>();

    cout << fv->GetCap() << endl;

    fv->Add(5);
    fv->Add(8);

    cout << fv->GetSize() << endl;

    delete fv;

    return 0;
}