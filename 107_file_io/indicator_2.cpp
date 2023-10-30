#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(void) {

    istringstream sin("hello world dog cat wow");
    string a, b, c;

    sin >> a;
    cout << a << endl;                               // hello
    cout << "indicator at: " << sin.tellg() << endl; // 5. hello를 뽑아 냈으므로

    sin.seekg(6, ios::cur); // 현재 위치에서 6칸 뒤로 indicator 이동
    sin >> b;
    cout << b << endl; // dog 출력

    sin.seekg(0, ios::beg);                          // rewind. 맨 앞으로 이동
    cout << "indicator at: " << sin.tellg() << endl; // 0

    sin.seekg(-7, ios::end); // 맨 뒤에서 7칸 앞으로
    sin >> c;
    cout << c << endl;                               // cat
    cout << "indicator at: " << sin.tellg() << endl; // 19

    return 0;
}