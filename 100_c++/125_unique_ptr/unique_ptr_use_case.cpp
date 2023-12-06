#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Vector {
public:
    Vector() = delete;
    Vector(double x, double y) : mX(x), mY(y){};
    virtual ~Vector() {
        cout << "good bye" << endl;
    }

    void Print() {
        cout << "vector : " << mX << " " << mY << endl;
    }

private:
    double mX;
    double mY;
};

// 유용한 사례 1.
// 클래스 내 멤버 객체를 unique ptr로 선언하여 메모리 정리할 필요 없음.
class Player {
public:
    Player() : mLocation(new Vector(1.1, 1.1)) {
    }
    virtual ~Player() {
        // mLocation을 delete할 필요 없음.
    }

private:
    unique_ptr<Vector> mLocation;
};

int main(void) {

    // 유용한 사례 2.
    // heap 할당하고 싶은데 메모리 정리가 번거로울 때.
    // 혹은 까먹어도 안전할 때.
    unique_ptr<Vector> vec(new Vector(1.1, 1.1));

    // 유용한 사례 3.
    // STL container에서 객체의 포인터 형을 저장한다면
    // 다 사용한 후에 for문 돌아가면서 하나하나 메모리 정리를 해주어야 했다.
    // 참고)
    /*
        stl container 등에 객체의 포인터형을 저장했다면,
        해당 container를 사용 후에는 모든 원소에 대해서 메모리 정리를 해주어야 함.
        (114_stl_container/vector/ptr_vector_heap_cleanup.cpp) 참고
    */
    // 그러나 애초에 unique_ptr로 선언했다면 자동 수거 되므로 문제 없음.
    vector<unique_ptr<Vector>> v;

    v.push_back(unique_ptr<Vector>(new Vector(1.2, 5.4)));
    v.push_back(unique_ptr<Vector>(new Vector(2.2, 5.4)));

    return 0;
}
