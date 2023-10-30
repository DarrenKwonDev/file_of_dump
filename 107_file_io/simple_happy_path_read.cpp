#include <fstream>
#include <iostream>

using namespace std;

/*
    간단한 읽기이며, 견고한 처리가 아님에 주의.
*/

int main(void) {
    ifstream fin;
    fin.open("./hello.txt");

    // read one char
    char ch;
    while (true) {
        fin.get(ch);
        if (fin.fail()) {
            break;
        }
        cout << ch;
    }

    // 단어 하나 읽기
    char word[20];
    fin >> word;
    cout << word;

    // 한 줄 읽어오기 (라기보단 지정된 갯수 만큼 읽어오기)
    // getline을 사용했으므로 \n을 만날 때 까지 읽으며 \n는 스트림에서 삭제.
    char buff[32];
    fin.getline(buff, 31);
    printf("%s", buff);

    // 한 줄 읽기
    string line;
    while (!fin.eof()) {
        getline(fin, line);
        cout << line << endl;
    }

    fin.close();

    return 0;
}