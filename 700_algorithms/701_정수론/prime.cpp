#include <bits/stdc++.h>

using namespace std;

/*
    소수 판별 : 2 이상 sqrt(n) 이하의 수 중 나누어 떨어지는 것이 없다면 소수.
    왜?
    n이 소수가 아니라면 n = ab 꼴로 표현할 수 있을 것이고,
    1 < a, b < n일 것이다.
    만약 둘다 a, b > sqrt(n)이라면 ab > n이 되어 버릴 것이기 때문.
    따라서 sqrt(n) 까지만 확인하면 된다.

    https://rkm0959.tistory.com/178 참고.
*/

int cache[1000001] = {
    0,
};

bool is_prime(int n) {

    if (cache[n]) {
        return true;
    }

    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    cache[n] = 1;
    return true;
}

int main(void) {
}