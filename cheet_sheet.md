char

int | -2,147,483,648 ~ +2,147,483,647 %d
unsigned int | 0 ~ 4294967295 %u size_t (1 << 32)
long | -2,147,483,648~ 2,147,483,647 | int랑 차이가 없네? 그렇다. 그래서 long 안 쓴다.
long long int | -9,223,372,036,854,775,808 ~ +9,223,372,036,854,775,807 | %lld
float 3.4*10-38 ~ +- 3.4*1038 %f 정밀도 6자리
double +- 1.7*10-308 ~ +- 1.7*10308 %lf 정밀도 15자리

논리 연산자
!(not), &&(and), ||(or)
!(a||b) = !a && !b

비트단위(bitwise)연산자
~(bitwise not), &(bitwise and), |(bitwise or), ^(bitwise xor),
<<(bitwise left shift), >>(bitwise right shift)

```c
/*
heuristic

전위 연산은 오른쪽으로 평가함
*++p는 ++먼저하고 *
++*p는 *먼저하고 ++

후위 연산이 존재할 경우 앞서 모든 작업을 처리한 후 후위 연산 적용
괄호가 있으면 괄호 먼저.
*/
int main(void) {
    int nums[] = {134, 68, 47956};
    int* p = nums; /* 변수 nums의 주소가 0x104라 가정 */

    // 역참조 먼저 + 후위 연산 나중에
    int num = *p++; // num: 134, p: 0x108
    printf("%d, %p\n", num, p);

    // 역참조 먼저 + 후위 연산 나중에
    // 후위 연산이므로 num엔 134가 반영됨.
    int num = (*p)++; // num: 134, p: 0x104
    printf("%d, %p\n", num, p);

    // // 전위 연산 먼저 + 역참조 나중에
    int num = *++p; // num: 68, p: 0x108
    printf("%d, %p\n", num, p);

    // // 역참조 먼저 + 전위 연산 (as a int)
    int num = ++*p; // num: 135, p: 0x104
    printf("%d, %p\n", num, p);
}
```

-   `int* const`
    -   주소를 보호하는 ptr
    -   <u>포인터의 메모리를 고정하고 싶을 때 사용함. 메모리가 가리키는 값은 변경 가능</u>
        -   ```c
            int* const p = &a;
            *p = b; // ok
            p = &b; // error
            p++;    // error
            ```
    -   <u>ptr = &new 꼴 불가.</u>
-   `const int*`

    -   값을 보호하는 ptr
    -   <u>포인터가 가리키는 값을 고정하고 싶을 때 사용함. 포인터가 담은 메모리 주소를 변경 가능</u>
    -   <u>\*ptr = new 꼴 불가.</u>
    -   ptr를 통한 값 변경을 막는 것이지 그 외의 작업은 가능.
        -   ```c
            const int* p = &a;
            a = 10; // ok.
            p = &b; // ok.
            *p = 5; // error
            ```

```c
int(*ptr)[3] = arr; // 열이 3인 2차원 배열 포인터
int* ptr2[3] = arr; // [int*, int*, int*] 형태의 배열
```

---
