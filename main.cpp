
#include <vector>

// template class에 대응하기 위한 by pass interface
class InterfaceOfA {};

template <typename T>
class A : public InterfaceOfA {};

int main(void) {
    // std::vector<A>; // no.
    std::vector<InterfaceOfA> v; // this will do.
    return 0;
}