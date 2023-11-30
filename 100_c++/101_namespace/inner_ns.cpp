#include <iostream>

using namespace std;

namespace outer {
namespace inner {
void printsomething() {
    cout << "양고기";
}
} // namespace inner

} // namespace outer

int main(void) {

    outer::inner::printsomething();

    return 0;
}