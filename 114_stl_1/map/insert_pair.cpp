#include <iostream>
#include <map>

using namespace std;

/*
    insert
    https://en.cppreference.com/w/cpp/container/map/insert

    pair
    https://en.cppreference.com/w/cpp/utility/pair
    A pair is a specific case of a std::tuple with two elements.
*/
int main(void) {
    map<string, string> cryptoMap;
    map<string, string>::iterator i;

    // pair
    pair<string, string> btcAlias("BTC", "bitcoin");
    cout << btcAlias.first << endl;
    cout << btcAlias.second << endl;

    // insert
    const auto [it, success] = cryptoMap.insert(btcAlias);
    cout << it->first << endl; // 삽입된 곳을 가리키는 iter 반환.
    cout << success << endl;   // 1 (성공)
    const auto [_, is_success] = cryptoMap.insert(pair<string, string>("BTC", "silent fail"));
    cout << is_success << endl; // 0 (실패)

    // operator[]
    cryptoMap["BTC"] = "bItCoIn"; // key:value overwrite
    cryptoMap["XRP"] = "ripple";  // key:value created
    cryptoMap["ADA"] = "cardano"; // key:value created

    cout << cryptoMap["BTC"] << endl;
    cout << cryptoMap["XRP"] << endl;

    // insert할 때부터 key가 알파벳 순으로 정렬됨.
    for (i = cryptoMap.begin(); i != cryptoMap.end(); i++) {
        cout << i->first << endl;
    }

    return 0;
}
리