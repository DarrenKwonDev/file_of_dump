#include <exception>
#include <iostream>

using namespace std;

struct SlotNullException : public exception {

    // exception의 what override
    const char* what() const throw() {
        return "slot is NULL";
    }
};

class Bag {
public:
    Bag(int slotCount) : mSlotCount(slotCount) {
        int* mSlots = new int[mSlotCount];

        // heap 할당에 실패했다면 NULL을 반환함.
        // 이럴 경우는 메모리가 꽉 찼을 때나 발생함.
        // 차라리 프로그램 크래시하는 게 나을 지도 모름.
        if (mSlots == NULL) {
            throw SlotNullException();
        }
    }
    virtual ~Bag() {
        cout << "virtual deconstructor clean up process" << endl;
        delete[] mSlots;
    }

private:
    int mSlotCount;
    int* mSlots;
};

int main(void) {
    Bag* bag = new Bag(30);

    delete bag;

    return 0;
}
