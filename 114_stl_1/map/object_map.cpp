#include <iostream>
#include <map>

using namespace std;

class MonsterInfo {
public:
    MonsterInfo(string name, string monsterID) : mName(name), mMonsterID(monsterID) {}
    virtual ~MonsterInfo() {}

    // map인 key가 오름차순으로 정렬되어야 하므로
    // operator<를 정의해야만 comp 함수가 돌아 정렬이 가능해진다.
    bool operator<(const MonsterInfo& other) const {
        if (mName == other.mName) {
            return mMonsterID < other.mMonsterID;
        }
        return mName < other.mName;
    }

private:
    string mName;
    string mMonsterID;
};

int main(void) {
    map<MonsterInfo, int> simpleMap;

    simpleMap.insert(pair<MonsterInfo, int>(MonsterInfo("rabbit", "m556"), 10));
    simpleMap.insert(pair<MonsterInfo, int>(MonsterInfo("crab", "m711"), 25));

    // 25를 반환.
    // 즉, operator< 에 의해 crab이 첫번째 원소로 정렬됨.
    cout << simpleMap.begin()->second << endl;

    return 0;
}
