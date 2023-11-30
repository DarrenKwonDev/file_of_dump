#include <iomanip>
#include <iostream>

using namespace std;

/*
        input, output manipulator
        https://en.cppreference.com/w/cpp/io/manip

        한 번 flags가 세팅되면 그 이후 cout에 영향이 미침.
        예를 들어
        ```cpp
        cout << boolalpha << true;
        cout << true;
        ```
        2번째 줄은 별다른 manipulate가 없어도 'true'로 출력됨.

        아래와 같이 cout의 setf (set flags) 메서드를 통해 플래그 세팅한 것과 같음.
        ```cpp
        cout.setf(ios_base::boolalpha);
        cout << true;
        ```
*/
int main(void) {

    // showbase and 진법
    // showbase : controls whether prefix is used to indicate numeric base
    cout << showbase << dec << 14 << endl;
    cout << noshowbase << hex << 14 << endl;
    cout << showbase << oct << 14 << endl;

    // pos = positive
    cout << showpos << 123 << endl;   // +123
    cout << noshowpos << 123 << endl; // 123

    // uppercase
    cout << showbase << uppercase << hex << 1235 << endl; // 0X4D3

    // left, right, internal (https://en.cppreference.com/w/cpp/io/manip/left)
    // internal = 부호는 왼쪽, 숫자를 오른쪽 정렬을 말함.
    cout << setw(6) << left << -12 << endl;     //'-12   '
    cout << setw(6) << right << -12 << endl;    //'   -12'
    cout << setw(6) << internal << -12 << endl; //'-   12'.

    // (no)showpoint = 무의미한 소숫점 자리의 0을 제거하여 보여줌.
    cout << noshowpoint << 3.14100 << " " << 3.0 << endl;
    cout << showpoint << 3.14100 << " " << 3.0 << endl;

    // fixed, scientific, hexfloat, ...
    // https://en.cppreference.com/w/cpp/io/manip/fixed
    cout << fixed << 3.14159;
    cout << scientific << 3.14159;

    // boolalpha = true/false를 문자열로 보여줄 것. (alphabet으로 보여줘라.)
    cout << boolalpha << true;
    cout << noboolalpha << true;

    // #include <iomanip>
    cout << setw(5) << 14 << endl;
    cout << setfill('*') << setw(5) << 14 << endl;
    cout << setprecision(5) << 3.1041592 << endl;

    // method way
    cout.setf(ios_base::boolalpha);
    cout.setf(ios_base::hex, ios_base::basefield);
    cout << true << " " << 15; // true f

    return 0;
}