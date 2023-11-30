#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
    ifstream fin;
    fin.open("hello.txt");

    int number;
    string trash;

    while (!fin.eof()) {
        fin >> number; // 숫자만 읽으려고 함.

        if (fin.fail()) { // 숫자가 아닌 다른 값이 들어온 경우
            fin.clear();  // 스트림 상태를 정상으로 되돌린다.
            fin >> trash; // 다른 값을 trash string에 담아준다.
        } else {
            cout << number << endl;
        }
    }

    fin.close();

    return 0;
}