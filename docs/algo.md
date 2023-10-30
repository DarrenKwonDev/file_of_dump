# cpp algo note

## gtime

```bash
nodemon --exec "g++-13 -std=c++17 ./*.cpp && gtime -f '\n%P cpu \n%es exeuction time\nmomery %MKB' ./a.out < ./input" -e cpp
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

-   list(circular doubly linked list)
    -   list<T>::iterator는 list 메서드에 의해 자동으로 보정되지 않는다.
        -   list<T>의 iterator는 코더의 의도하지 않은 삭제되거나 이동된 원소를 가리키고 있을 수 있다. 메모리에서 해당 원소 자체가 삭제되는 것이 아니기에. 따라서 대부분의 경우 `iter = list.erase(iter)`, `iter = list.insert(iter)` 와 같이 사용하기를 원할 것이다.
        -   insert 함수는 insert한 원소를 가리키는 iterator를 반환합니다
        -   erase 함수는 지워진 원소의 다음 원소를 가리키는 iterator를 반환. 빈 리스트나 마지막 원소를 지우려는 경우 에러 발생
            -   Thus the end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for pos.
                -   ```cpp
                        list<int> l = {1};
                        list<int>::iterator i = l.end(); // i는 실제 데이터가 아닌 리스트의 끝을 나타내는 특별한 위치.
                        // 실제 원소 3을 지우기 위하여 --i를 통해서 원소 3을 가리킴.
                        // 그 결과 l.erase는 3을 지우게 되고 3의 다음 원소를 반환할 것으로 예상됨.
                        // 그러나 3의 다음 원소는 없음.
                        // 이 경우 문서를 읽어보면
                        // If pos refers to the last element, then the end() iterator is returned.
                        i = l.erase(--i);
                        // 마지막 원소를 지운 경우 똑같이 마지막을 반환함.
                        cout << *i << endl; // 2
                    ```
-   list.end는 실제 데이터가 아닌 리스트의 끝을 나타내는 특별한 위치를 가리킴. 몇 컴파일러에서는 알아서 보정을 해줍니다만 여기에 의존하지 않는 것이 좋습니다.
    -   ```cpp
            int main(void) {
            list<int> l = {1, 2};
            list<int>::iterator cur = l.end();
            cout << *cur << endl;     // 2 (UB)
            cout << *(--cur) << endl; // 2 (의도된 것)
        }
        ```

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
