#include <stdio.h>

// 6과 8의 최대공약수
// gcd(6, 8) a = 6, b = 8
// gcd(8, 6) a = 8, b = 6
// gcd(6, 2) a = 6, b = 2
// gcd(2, 0) a = 2, b = 0
// 2
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// 최소 공배수
// 6과 8의 최소공배수
// 6 * 8 / gcd(6, 8) = 24
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int gcd_ab = gcd(a, b);
    int gcd_abc = gcd(gcd_ab, c);
    int lcm_ab = lcm(a, b);
    int lcm_abc = lcm(lcm_ab, c);
    printf("%d\n", lcm_abc);
}
