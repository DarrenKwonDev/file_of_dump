#include <iostream>
#include <sstream>

using namespace std;

/*
    sstream
    (string stream)
    https://en.cppreference.com/w/cpp/header/sstream

    std::istringstream (cin, sscanf 비슷)
    std::ostringstream (cout, sprintf 비슷)
*/
int main(void) {

    istringstream string_stream = istringstream("hello");
    char ch = string_stream.get();
    cout << ch << endl;

    ostringstream string_out = ostringstream();
    string_out << "why not";
    cout << string_out.str();

    return 0;
}