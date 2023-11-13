# cpp algo note

## mental model

자료구조 보듯 insert, search, delete의 시간 및 공간 복잡도를 고려.

각 세부 동작이 존재하는 것도 살펴볼 것.
search: linear, binary, hash table(occur array), ...
sort : quick, bubble, merge, eap, ...
reverse

## gtime

```bash
nodemon --exec "g++-13 -std=c++17 ./*.cpp && gtime -f '\n%P cpu \n%es exeuction time\nmomery %MKB' ./a.out < ./input" -e cpp c
\\
nodemon --exec "g++-13 -std=c++17 ./*.cpp && ./a.out" -e cpp
\\
nodemon --exec "g++-13 -std=c++17 ./*.cpp && ./a.out < ./input" -e cpp
```

## 자료형

-   int는 약 21억(2,147,483,648)
-   10^10 까지는 담을 수 있음. 그 이상은 long long int에 담을 것
-   arr, string
    -   insert, erase: O(N);

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

https://www.acmicpc.net/blog/view/128

-   printf/scanf와 cout/cin의 호출 순서에 따른 입출력을 위해 동기화가 기본적으로 유지 됨. 그러나 cout/cin만 쓴다면 동기화를 끊는 것이 속도 향상에 유리.

-   cin 을 사용할 때 마다 cout 에 flush 연산이 발생합니다. flush 연산은 출력 버퍼에 보관하고 있었던 내용을 모두 출력하고 출력 버퍼를 비우는 연산으로, 매우 무거운 연산입니다. 특히나 cin, cout을 번갈아 쓸 때 이 flush가 계속 발생하면 시간 초과 나곤 함. cin.tie(nullptr); 를 넣으면 cin과 cout 를 번갈아가며 사용해도 flush 연산을 수행하지 않게 되면서 수행 시간을 상당히 줄일 수 있습니다.

```cpp
ios::sync_with_stdio(0); // cpp stream와 c stream의 동기화 끊기
cin.tie(0); // cin 전에 cout 버퍼를 비우지 않도록 함.
```

## size() - 1 금지

```cpp
// don't do that.
// v.size()가 0인 경우 unsigned 자료형을 반환하는 v.size()가 overflow됨.
for (int i = 0; i <= v.size() - 1; i++) {
    /* code */
}
```

## num, char

```c
// char to num
printf("%d\n", c - '0'); // '6' - '0' = 54 - 48 = 6

// num to char
printf("%d\n", 5 + '0'); // '6' + '0' = 54 + 48 = 102

// b의 아스키 코드를 숫자 '1'로 표현(보통 occur array에 넣기 위해 사용함.)
'b' - 'a'
```

문자를 숫자로 변환하는 원리:
문자 '6'의 ASCII 코드 값은 54이고, '0'의 ASCII 코드 값은 48입니다.
따라서 '6' - '0'은 문자 '6'의 ASCII 코드 값(54)에서 '0'의 ASCII 코드 값(48)을 빼면 6이 됩니다. 이렇게 함으로써 문자 '6'이 숫자 6으로 변환됩니다.

숫자를 문자로 변환하는 원리:
숫자 5에 '0'의 ASCII 코드 값(48)을 더하면, 5 + 48은 53 + 48으로 101이 됩니다.
따라서 5 + '0'은 숫자 5에 '0'의 ASCII 코드 값을 더하여 문자 '6'의 ASCII 코드 값(101)을 얻습니다. 이렇게 함으로써 숫자 5가 문자 '6'으로 변환됩니다.

결국 문자의 ASCII가 숫자보다 높으니까 문자로 변환할 때는 + 숫자로 변환할 때는 - 로 기억하자.

## 올림, 반올림, 내림

```c

// 10의 자리까지 내림, 반올림, 올림
int floor_down = (n / 10) * 10;
int round_up = ((n + 5) / 10) * 10;
int ceil_up = ((n + 9) / 10) * 10;

// 소수점 버림, 올림
(a + b + 1) / 2 // 소수점 올림. 3.5 -> 4
(a + b) / 2 // 소수점 버림. 3.5 -> 3

// k로 나눈 몫의 올림
(a + (k - 1)) / k;
```

## counting array(occur array)

배열의 인덱스를 특정 수의 존재 여부 혹은 존재 갯수로 활용하는 방식.
해시맵의 기본 아이디어.

## permutation

## structured binding

struct, map 등에 대해서 javascript에서 하듯 deconstruct할 수 있음.

199_cpp_trics/structued_binding.cpp 참고

## etc

std::find_if
