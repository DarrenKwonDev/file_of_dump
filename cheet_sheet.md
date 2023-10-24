char
int | -2,147,483,648 ~ +2,147,483,647 %d
unsigned int | 0 ~ 4294967295 %u size_t (1 << 32)
long | -2,147,483,648~ 2,147,483,647 | int랑 차이가 없네? 그렇다. 그래서 long 안 쓴다. 다른 언어에선 long이 64
long long int | -9,223,372,036,854,775,808 ~ +9,223,372,036,854,775,807 | %lld

float | 3.4*10-38 ~ - 3.4*1038 | %f | 정밀도 6자리
double | 1.7*10-308 ~ - 1.7*10308 | %lf | 정밀도 15자리
long double | 잘 안 쓰고, double이랑 사이즈도 같던데... | %Lf | 정밀도 15자리

컴파일러마다 정밀도가 다름.
clang에서는
float의 정밀도: 6
double의 정밀도: 15
long double의 정밀도: 15

실수는 (1.m) \* 2 ^ (e - 127) 꼴로 실수의 근사치로 저장됨.

논리 연산자
!(not), &&(and), ||(or)
!(a||b) = !a && !b

비트단위(bitwise)연산자
~(bitwise not), &(bitwise and), |(bitwise or), ^(bitwise xor),
<<(bitwise left shift), >>(bitwise right shift)

---

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

    // p + 1 ==  ++p == ptr1[1]
    // (char*)ptr1 + 1 == 1비트 이동해.
}
```

---

-   `int* const`
    -   주소를 보호하는 ptr
    -   <u>포인터의 메모리를 고정하고 싶을 때 사용함. 메모리가 가리키는 값은 변경 가능</u>
        -   ```c
            int* const p = &a;
            *p = b; // okz
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

---

[rt_lt rule](https://cseweb.ucsd.edu/~gbournou/CSE131/rt_lt.rule.html)

-   as "pointer to" - always on the left side
-   [] as "array of" - always on the right side
-   () as "function returning" - always on the right side

```c
int *a; // a is pointer to int
int **a; // a is pointer to pointer to int
int *p[]; // p is array of pointer to int
int (*p)(char); // p is pointer to function (char) -> int
int (*f[2])(float, float); // f is array of pointers to (float, float) -> int
char (*foo)(void*) // foo is pointer to (void*) -> char
int* (*foo)(int, void(*)(int)) // foo is pointer to (int, void(*)(int)) -> int*
void (*func(int, void (*)(int)))(int); // func is function retuning pointer to function (int) -> void
int (*(*fun_one)(char *,double))[9][20]; // fun_one is pointer to function expecting (char *,double) and returning pointer to array (size 9) of array (size 20) of int.
void (*(*f[])())() // f is array of pointer to function () -> pointer to function () -> void
```

---

-   동적 할당 작성시 원칙

-   기타

    -   최대한 정적 메모리(stack)를 사용하고, 동적 메모리(heap)는 최소한으로 사용하는 것이 좋다.
    -   접두사로 pa\_ (pointer allocated) 를 붙여 malloc되었다는 것을 명시하는 것이 좋다.

-   할당

    1. malloc으로 할당 받은 포인터는 복사하여 사용하라.
        - 해당 주소가 바뀌면 free할 수가 없기 때문이다.

-   재할당

    1. realloc을 한다고 했을 때 동일한 포인터를 반환받을 수 있을 지는 모른다.
    2. realloc의 반환값은 항상 임시 포인터 변수에 담은 후 NULL이 아닌 것을 체크한 후에 원래 포인터에 대입할 것.
        - realloc이 실패하면 기존 메모리를 해제하지 않고, 원래 ptr 주소를 상실해서 메모리 누수가 발생할 수 있음.
        - 그러나 NULL을 반환할 정도라면 프로그램 뻗는게 맞다고 생각해서 에러 핸들링 안하는 경우도 종종 있다.

-   해제

    1. free 먼저 작성.
        - 특히 지역 변수 내 malloc한 경우 함수 종료 시 그냥 나가버리면 해당 메모리 주소를 잃어버리게 되어 free할 수 없으니 유의.
    2. free한 뒤에 변수에 NULL을 대입하여 초기화 할 것
        -   1. null ptr는 free로 전달해도 안전함.
        -   2. 해제된 것이라는 것은 명확히 함.
    3. 기타 free 주의점
        - free한 메모리를 또 free하면 안 됨
        - 해제만 메모리를 사용하려고 하면 안 됨

-   동적 메모리의 소유권
    -   동적 메모리를 생성한 함수에서 그 메모리를 해제할 책임이 있다.
        -   소유주가 아닌 것이 메모리를 해제하면 안된다.
        -   간단한 휴리스틱으로 malloc한 곳에서 free하면 된다는 원칙 적용.
    -   cpp에서의 RAII(자원 획득은 초기화, resource acquisition is initialization)와 유사한 개념이다.

---

가변인자

```c
va_list ap;
va_start(ap)
{
    va_arg(ap, int)
}
va_end(ap)
va_copy
```

---

-   입력 받기의 전략

1. 한 글자씩 읽기

    - [getchar](https://en.cppreference.com/w/c/io/getchar), fgetc(putchar, fputc) : 한 글자씩 읽고 쓴다.

2. 한 줄씩 읽기(문자열 단위)
    - [fgets](https://en.cppreference.com/w/c/io/fgets)
        - char *fgets( char *str, int count, FILE \*stream );
        - stream에서 count-1만큼 읽어서 str에 쓴다.
        - `개행문자도 읽어온다.` 따라서 strlen을 찍으면 \n 까지 읽어서 반환한다. -> 개행문자가 싫다면 scanf
        - `마지막에 \0(null char) 를 붙여`준다. 하지만 신뢰하지 말고 코드로 len - 1에 null char를 넣어주자.
        - 공백이 있는 문자열을 받기 위해서 scanf 대신 fgets를 쓰는게 편리한 편.
    - gets는 쓰지 말자.
3. 한 데이터씩 읽기(형식화된 데이터)
    - [scanf](https://en.cppreference.com/w/c/io/fscanf)
    - 데이터를 구분 짓는 기준이 공백임. 따라서 공백을 잘라 읽는다. i love you 에서 i만 읽어옴. scanf는 문자열을 입력받기에 적절하지 않음. fgets나 다른 함수를 권고함.
4. 한 블록씩 읽기 (이진 데이터)
    - [fread](https://en.cppreference.com/w/c/io/fread)

C로 사용자 입력을 받았을 때 권장되는 방식은 `fgets`와 `sscanf`

---

-   <string.h>

    -   [memset](https://en.cppreference.com/w/c/string/byte/memset)
        -   void *memset( void *dest, int ch, size_t count );
        -   문자 ch를 count만큼 dest에 쓴다.
    -   [memcpy](https://en.cppreference.com/w/c/string/byte/memcpy)
        -   void* memcpy( void *dest, const void \*src, size_t count );
        -   src를 count만큼 읽어서 dest에 쓴다.
    -   [memcmp](https://en.cppreference.com/w/c/string/byte/memcmp)
        -   int memcmp( const void* lhs, const void* rhs, size_t count );
        -   count만큼 메모리를 비교. \0을 만나도 비교를 진행함.
