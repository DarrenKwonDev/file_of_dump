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

void test(shared_ptr<Vector> k) {

    cout << "k use cnt " << k.use_count() << endl;
    return;
}

int main(void) {

    shared_ptr<Vector> vec = make_shared<Vector>(1.1, 2.2);
    shared_ptr<Vector> vec2 = vec;
    shared_ptr<Vector> vec3 = vec2;

    cout << vec.use_count() << endl;  // 3
    cout << vec2.use_count() << endl; // 3
    cout << vec3.use_count() << endl; // 3
    cout << "-----" << endl;

    vec = nullptr;

    cout << vec.use_count() << endl;  // 0
    cout << vec2.use_count() << endl; // 2
    cout << vec3.use_count() << endl; // 2
    cout << "-----" << endl;

    test(vec2);
    cout << vec2.use_count() << endl; // 2
    cout << vec3.use_count() << endl; // 2
    cout << "-----" << endl;

    return 0;
}
