#include <bits/stdc++.h>
using namespace std;

// 복사생성자. 타 언어에서의 clone, .copy와 같은 작업을 생성자 단에서 지원.
// 1. 얕은 복사기 때문에 원본이 mutate됨.
// 2. 해당 복사 생성자가 없어도 컴파일러에서 그대로 넣어줌.
// 따라서 클래스 내부에서 포인터 변수가 존재한다면 깊은 복사하는 커스텀 복사 생성자를 만드는 것이 좋음.

class Record {
public:
    // 일반적으로, 일반 값(단순 대입 가능) initializer list에서 할당하고
    // 별도의 처리가 필요한 배열, 구조체 등은 함수 body 내에서 처리함.
    // 가독성이 좋아지는 편임.
    Record(const int* scores, int count) : mCount(count) {
        mScores = new int[mCount]; // mCount 만큼의 int 배열 heap 할당
        memcpy(mScores, scores, mCount * sizeof(int));
    };

    // deep copy initializer
    Record(const Record& other) : mCount(other.mCount) {
        // 새롭게 배열 파서 깊은 복사 처리.
        mScores = new int[mCount];
        memcpy(mScores, other.mScores, mCount * sizeof(int));
    }

    // deconstructor
    ~Record() {
        delete[] mScores;
    };

    void IterScores() {
        int* p = mScores;
        for (int i = 0; i < mCount; i++) {
            cout << *p << endl;
            p++;
        }
        p = NULL;
    }

    int mCount;
    int* mScores;
};

int main(void) {
    int scores[5] = {1, 2, 3, 4, 5};

    Record* k = new Record(scores, 5);
    Record* copied = new Record(*k);

    delete k; // 소멸자에 의해 k 소유한 mScores의 힙 메모리도 정리됨.

    copied->IterScores(); // k의 mScores와 별도의 힙 메모리 공간에 저장하고 있으므로 정상적으로 출력됨.

    return 0;
}