
#include <iostream>

using namespace std;

int main(void) {
    char buffer[100];

    // 9개의 문자 읽어옴. 마지막은 null char(\0)를 넣어줌.
    // \n는 입력 스트림에 남아 있음.
    // https://en.cppreference.com/w/cpp/io/basic_istream/get
    cin.get(buffer, 10);
    printf("%s\n", buffer);

    // 9개의 문자 읽어옴. 마지막은 null char(\0)를 넣어줌.
    // get과 달리 \n는 입력 스트림에 없음. 그래서 get'line'
    // https://en.cppreference.com/w/cpp/io/basic_istream/getline
    cin.getline(buffer, 10, '!'); // read until met '!'
    printf("%s\n", buffer);

    return 0;
}