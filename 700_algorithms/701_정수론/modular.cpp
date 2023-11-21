#include <bits/stdc++.h>

using namespace std;

// https://www.acmicpc.net/problem/4375
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    while (cin >> n) {
        long long num = 1;
        int cnt = 1;

        while (1) {
            if (num % n == 0) {
                cout << cnt << "\n";
                break;
            } else {
                // num * 10 + 1 꼴로 커집니다. num * 10 + 1 가 overflow 가능성이 존재합니다.
                // 구하려는 식이 (num * 10 + 1) % n 이므로 모듈러 연산을 통해 수를 줄입시다.

                // step 1.
                // k = (num * 10)라 합시다.
                // (k + 1) % n 입니다.
                // 이는 ((k % n) + (1 % n)) % n로 연산됩니다.

                // step 2.
                // ((k % n) + (1 % n)) % n 에서 (k % n)을 모듈러 연산으로 낮춰봅시다.
                // ((num * 10) % n)는 모듈러 연산에 의해 다음과 같이 풀이됩니다.
                // ((num % n) * (10 % n)) % n

                // step 3.
                // 따라서 (num * 10 + 1) % n는 아래와 같이 정리됩니다.
                // ((((num % n) * (10 % n)) % n) + (1 % n)) % n
                // 여기서 우리는 % n 까지한 값이 이나리 % n 으로 나눌 값을 넘겨서 나누어 떨어지는지 확인해야 합니다.
                // 그래서 끝의 %n을 제외한 값을 재할당하면 됩니다.

                num = (((num % n) * (10 % n)) % n) + (1 % n);
                cnt++;
            }
        }
    }
}