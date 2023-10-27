# cpp algo note

## gtime

```bash
nodemon --exec "clang++ -std=c++17 ./*.cpp && gtime -f '\n%P cpu \n%es exeuction time\nmomery %MKB' ./a.out" -e cpp
\\
nodemon --exec "clang++ -std=c++17 ./*.cpp && ./a.out" -e cpp
```

## 자료형

-   int는 약 21억(2,147,483,648)
-   10^10 까지는 담을 수 있음. 그 이상은 long long int에 담을 것

## 실수의 동등 비교

float은 상대 오차 10-6까지 안전하고 double은 10-15까지 안전하다는 소리입니다.
즉, double 1.0은 1 +- 10-15의 범위를 가지고, float 1.0은 1 +- 10-6의 범위를 가진다는 것입니다.

따라서 이러한 자료형을 가진 값이 같은지 판단할 때는 두 수차의 절대값이 아주 작은 지를 판단하면 된다. (1e-9 정도면 충분)

```cpp
#include <iostream>

int main(void) {

    double a = 0.1 + 0.1 + 0.1;
    double b = 0.3;

    if (a == b) { // 출력 안 됨
        std::cout << "same 1" << std::endl;
    }
    if (abs(a - b) <= 1e-9) { // 출력됨
        std::cout << "same 2" << std::endl;
    }

    return 0;
}
```

## reference

c/cpp는 다 pass by value이다. 이 과정 때문에 시간 복잡도가 올라가니 값을 넘겨줄 때에도 유의할 것.

```cpp
// no. every vector is copied
bool comp1(vector<int> v1, vector<int> v2, int idx) {
    return v1[idx] > v2[idx];
}

// yes. only reference is copied
bool comp2(vector<int>& v1, vector<int>& v2, int idx) {
    return v1[idx] > v2[idx];
}
```

## cpp stream과 c stream의 동기화 끊기 + cout 버퍼 비우지 않기

printf/scanf와 cout/cin의 호출 순서에 따른 입출력을 위해 동기화가 기본적으로 유지 됨.
그러나 cout/cin만 쓴다면 동기화를 끊는 것이 속도 향상에 유리.

```cpp
ios::sync_with_stdio(0); // cpp stream와 c stream의 동기화 끊기
cin.tie(0); // cin 전에 cout 버퍼를 비우지 않도록 함.
```
