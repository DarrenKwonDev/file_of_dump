#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Vector {
public:
    Vector() : mX(0), mY(0){};
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

int main(void) {

    shared_ptr<Vector> vec = make_shared<Vector>(1.1, 2.2);

    // 포인터 공유.
    shared_ptr<Vector> vec2 = vec; // + 1 strong ref

    Vector* naked = vec.get(); // ref count로 안 침. shared_ptr가 아니잖아.
    naked->Print();

    // 2.
    // vec, vec2가 ref cnt 이므로
    cout << "ref cnt are : " << vec.use_count() << endl;

    vec.reset(); // vec = nullptr; - 1 strong ref

    vec2->Print(); // vec2가 아직도 해당 자료를 가리키고 있으므로.

    // 1
    // vec이 nullptr가 되었으므로
    cout << "ref cnt are : " << vec2.use_count() << endl;

    return 0;
}
