#include <fstream>
#include <iostream>

using namespace std;

/*
    ifstream (input file stream). 읽기.
    ofstream (output file stream). 쓰기.
    fstream (file input/output both)

    open method에 대해서는
    https://en.cppreference.com/w/cpp/io/basic_ifstream/open
    https://en.cppreference.com/w/cpp/io/ios_base/openmode

    app:	seek to the end of stream before each write
    binary:	open in binary mode
    in:	open for reading
    out:	open for writing
    trunc:	discard the contents of the stream when opening
    ate:	seek to the end of stream immediately after open
    noreplace (C++23):	open in exclusive mode

*/
int main(void) {

    // 읽기 전용
    ifstream fin;
    fin.open("./hello.txt", ios::ate);
    if (fin.is_open()) {
        cout << "opened";
    }
    fin.close();

    // 쓰기 전용 (없으면 만듦)
    ofstream fout;
    fout.open("./hello.txt", ios::binary);
    fout.close();

    // 읽고 쓰기
    fstream fs;
    fs.open("./hello.txt", ios::app);
    fs.close();

    return 0;
}