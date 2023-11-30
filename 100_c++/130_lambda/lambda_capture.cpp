#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    https://en.cppreference.com/w/cpp/language/lambda#Lambda_capture
*/
int main() {

    float score = 35.3f;
    float score2 = 33.3f;

    // 노 캡처
    []() { cout << "no capture" << endl; }();

    // 값에 의한 외부 캡처
    auto valueCaptured = [=]() {
        cout << "using outside value capture " << score << endl;
        // 람다식 내부에서 수정 불가
        // score = 2.3f; // compile error
    };
    valueCaptured();

    // 참조에 의한 외부 캡처
    auto refCaptured = [&]() {
        // 람다식 내부에서 변경 가능.
        score = 2.3f; // 실제로 원본 값이 변경됨. mutate하니까 좀...
        cout << "ref capture " << score << endl;
    };
    refCaptured();

    // 특정 값복사 캡처
    auto specificValueCaptured = [score]() {
        cout << "capture " << score << endl;
    };
    specificValueCaptured();

    // 특정 레퍼런스 캡처
    auto specificRefCaptured = [&score]() {
        score = 100.f;
        cout << "capture " << score << endl;
    };
    specificRefCaptured();

    // 다 복붙해오는데 특정 변수만 레퍼런스로.
    auto captured = [=, &score2]() {

    };
    captured();

    return 0;
}