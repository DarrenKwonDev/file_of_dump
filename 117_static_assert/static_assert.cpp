#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int x;
    int y;
    char lolYouShouldMessUpHuH;
} Point_t;

int main() {
    static_assert(sizeof(Point_t) == 8, "Point_t should be 8 bytes");

    return 0;
}
