
#include <iostream>
#include <memory>

int main(void) {

    /*
        typeid는 const std::typeinfo&를 반환한다.
    */
    int* hNum = new int(3);
    const std::type_info& hNumInfo = typeid(hNum);
    std::cout << hNumInfo.name() << std::endl; // Pi

    std::unique_ptr<int> up = std::make_unique<int>(3);
    std::cout << typeid(up).name() << std::endl; // NSt3__110unique_ptrIiNS_14default_deleteIiEEEE

    int num = 3;
    std::cout << typeid(num).name() << std::endl; // i

    // typeif를 통해 값 비교
    if (typeid(3) == typeid(int)) {
        std::cout << "int!" << std::endl;
    }

    return 0;
}