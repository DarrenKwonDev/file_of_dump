#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, string delim) {
    vector<string> v;
    long long int pos = 0;
    string token;

    while ((pos = input.find(delim)) != string::npos) {
        token = input.substr(0, pos);
        v.push_back(token);
        input.erase(0, pos + delim.length());
    }
    v.push_back(input);
    return v;
}

int main(void) {
    auto v = split("abcfffeeerrffkkk", "ff");
    for (auto k : v) {
        cout << k << " ";
    }
}