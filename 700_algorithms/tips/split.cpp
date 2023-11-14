#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, string delim) {
    vector<string> ret;
    long long int pos = 0;
    string token = "";
    while ((pos = input.find(delim)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delim.length());
    }
    ret.push_back(input);
    return ret;
}

int main(void) {

    string s = "oh hello guys";
    vector<string> v = split(s, " ");

    for (auto k : v) {
        cout << k << "\n";
    }

    return 0;
}