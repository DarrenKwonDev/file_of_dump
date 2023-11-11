#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    float score = 35.3f;

    // 값에 의한 외부 캡처가 일어났으나
    auto valueCaptured = [=]() mutable {
        score = 2.3f; // compile error...가 안 남. mutable 한정자가 붙었으니
        cout << "using outside value capture " << score << endl;
    };
    valueCaptured();

    // 외부 변수에 영향을 미치지 않음.
    cout << score;

    return 0;
}