#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
    ofstream fout; // 쓰기용.
    fout.open("./hello.txt");

    fout.put('a'); // single char input

    string line;
    getline(cin, line);
    if (!cin.fail()) {
        fout << line << endl;
    }

    fout.close();

    return 0;
}