class DynamicArray {
private:
    int* data;
    int size;

public:
    // 복사 생성자
    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size]; // heap에 생성된 배열.
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // 대입 연산자 오버로드. 안하면 동일한 배열을 공유할테니 문제 생길 여지가 있어.
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data; // 기존의 자원을 해제
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // 소멸자 (동적으로 할당된 메모리를 해제)
    ~DynamicArray() {
        delete[] data;
    }
};

int main(void) {
    return 0;
}