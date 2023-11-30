#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
    fstream fs("./hello.txt");

    if (fs.is_open()) {

        // https://en.cppreference.com/w/cpp/io/basic_ostream/tellp
        cout << "current push ptr " << fs.tellp() << endl;

        // p는 put의 약자. 즉, 쓰기.
        // https://en.cppreference.com/w/cpp/io/basic_ostream/seekp
        fs.seekp(20, ios::beg);

        cout << "after seep put ptr " << fs.tellp() << endl;

        if (!fs.fail()) {
            // 21번째 문자부터 덮어씀.
            // 덮어쓰고 남은 문자는 그대로 존재
            // aaaaa|overwrite man|aaaaaa
            fs << "|overwrite man|";
        }
    }

    fs.close();

    return 0;
}