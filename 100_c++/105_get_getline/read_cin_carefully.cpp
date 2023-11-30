
#include <iostream>

using namespace std;

int main(void) {
    int number;
    int sum = 0;

    while (true) {
        cout << "iterate: ";
        cin >> number;
        if (cin.eof()) {
            break;
        }

        if (cin.fail()) {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(LLONG_MAX, '\n'); // 한 줄 버리기.
            continue;
        }

        cout << "got number " << number << endl;
        sum += number;
    }
    cin.clear();

    cout << "The sum is " << sum << endl;

    return 0;
}