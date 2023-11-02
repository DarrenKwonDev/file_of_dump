

<!-- toc -->

- [cpp_docs](#cpp_docs)
  * [권고 사항](#%EA%B6%8C%EA%B3%A0-%EC%82%AC%ED%95%AD)
  * [compiler](#compiler)
  * [stream input/output](#stream-inputoutput)
    + [stream 종류](#stream-%EC%A2%85%EB%A5%98)
    + [stream state](#stream-state)
    + [seek, indicator](#seek-indicator)
  * [class](#class)
    + [class에 암시적으로 정의되는 것들](#class%EC%97%90-%EC%95%94%EC%8B%9C%EC%A0%81%EC%9C%BC%EB%A1%9C-%EC%A0%95%EC%9D%98%EB%90%98%EB%8A%94-%EA%B2%83%EB%93%A4)
      - [new/delete와 malloc()/free()의 차이?](#newdelete%EC%99%80-mallocfree%EC%9D%98-%EC%B0%A8%EC%9D%B4)
      - [struct와 class의 차이?](#struct%EC%99%80-class%EC%9D%98-%EC%B0%A8%EC%9D%B4)
  * [class 상속](#class-%EC%83%81%EC%86%8D)
    + [생성자, 소멸자 호출 순서](#%EC%83%9D%EC%84%B1%EC%9E%90-%EC%86%8C%EB%A9%B8%EC%9E%90-%ED%98%B8%EC%B6%9C-%EC%88%9C%EC%84%9C)
    + [클래스와 메모리 레이아웃](#%ED%81%B4%EB%9E%98%EC%8A%A4%EC%99%80-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EB%A0%88%EC%9D%B4%EC%95%84%EC%9B%83)
    + [접근 제어 상속](#%EC%A0%91%EA%B7%BC-%EC%A0%9C%EC%96%B4-%EC%83%81%EC%86%8D)
    + [다중 상속은 안티패턴.](#%EB%8B%A4%EC%A4%91-%EC%83%81%EC%86%8D%EC%9D%80-%EC%95%88%ED%8B%B0%ED%8C%A8%ED%84%B4)
    + [추상 클래스(abstract class)와 순수 가상 함수(pure virtual function)](#%EC%B6%94%EC%83%81-%ED%81%B4%EB%9E%98%EC%8A%A4abstract-class%EC%99%80-%EC%88%9C%EC%88%98-%EA%B0%80%EC%83%81-%ED%95%A8%EC%88%98pure-virtual-function)
    + [interface](#interface)
  * [다형성](#%EB%8B%A4%ED%98%95%EC%84%B1)
    + [정적 바인딩(컴파일 바인딩) = 적은 대로 행한다.](#%EC%A0%95%EC%A0%81-%EB%B0%94%EC%9D%B8%EB%94%A9%EC%BB%B4%ED%8C%8C%EC%9D%BC-%EB%B0%94%EC%9D%B8%EB%94%A9--%EC%A0%81%EC%9D%80-%EB%8C%80%EB%A1%9C-%ED%96%89%ED%95%9C%EB%8B%A4)
    + [동적 바인딩(런타임 바인딩) = 가상 함수(virtual)로 실질을 런타임에 찾아 호출하도록 한다.](#%EB%8F%99%EC%A0%81-%EB%B0%94%EC%9D%B8%EB%94%A9%EB%9F%B0%ED%83%80%EC%9E%84-%EB%B0%94%EC%9D%B8%EB%94%A9--%EA%B0%80%EC%83%81-%ED%95%A8%EC%88%98virtual%EB%A1%9C-%EC%8B%A4%EC%A7%88%EC%9D%84-%EB%9F%B0%ED%83%80%EC%9E%84%EC%97%90-%EC%B0%BE%EC%95%84-%ED%98%B8%EC%B6%9C%ED%95%98%EB%8F%84%EB%A1%9D-%ED%95%9C%EB%8B%A4)
    + [가상 소멸자](#%EA%B0%80%EC%83%81-%EC%86%8C%EB%A9%B8%EC%9E%90)
  * [RAII(자원 획득은 초기화, resource acquisition is initialization)](#raii%EC%9E%90%EC%9B%90-%ED%9A%8D%EB%93%9D%EC%9D%80-%EC%B4%88%EA%B8%B0%ED%99%94-resource-acquisition-is-initialization)
  * [The rule of three/five/zero](#the-rule-of-threefivezero)
  * [etc](#etc)
    + [c의 헤더를 써도 되나?](#c%EC%9D%98-%ED%97%A4%EB%8D%94%EB%A5%BC-%EC%8D%A8%EB%8F%84-%EB%90%98%EB%82%98)
    + [string + string slow. why?](#string--string-slow-why)

<!-- tocstop -->

# cpp_docs

## 권고 사항

-   어셈블리 까보면 reference나 pointer나 같다. 다만 언어적 차원에서 reference가 좀 더 안전하게 쓰기 위해 만들어진 것. 많이 쓰자.

-   delete

    -   delete로 지울 수 있는 건 heap 할당된 객체 뿐임.
    -   new로 객체 선언한 건 heap에 할당되니 반드시 delete할 것. 배열은 delete[]로 삭제.

-   class

    -   모든 소멸자는 가상 소멸자로 작성하는 것이 좋다
    -   rule of three(five) / zero
    -   `클래스의  멤버 함수는 컴파일시 딱 한 번만 메모리에 할당됨`. 저수준에서 전역 함수와 그다지 다르지 않음. 개체마다 멤버 함수가 메모리에 위치한다면 상당한 공간 낭비.

-   struct

    -   struct는 C처럼 쓰기를 권장한다. (plain old data).
        struct에 생성, 소멸자, 메서드 할 수 있지만 하지 말자.
        순수하게 데이터만을 담아두자. 이래야 memcpy() 등 메모리 조작이 편안해진다.

-   읽기 전용 매개변수는 상수 참조로, 출력용 매개변수는 포인터로.
    -   func(int\* a, const int b, const int c)
    -   func(&a, b, c)

## compiler

apple : llvm(low level virtual machine) 기반 clang/calng++, lldb
linux : gcc(GNU compiler collection) 기반 gcc/g++, gdb
window : msvc

## stream input/output

### stream 종류

어떤 규칙성이 보일 것이다.

file : fstream / ifstream / ofstream  
string : stringstream / istringstream / ofstringstream  
console : cin / cout / cerr / clog

읽기(i) -> get (seekg, tellg)
쓰기(o) -> put (seekp, tellp)

### stream state

goodbit // good()  
eofbit // eof()  
failbit // fail()  
badbit // bad()

여기서 eof, fail, bad 상태 모두 알아둬야 하고 모두 큰 영향을 미친다.

-   입출력 연산이 스트림 상태 비트를 변화 시키고, 비트 상태에 따라 연산이 영향을 받는다.

    -   잘못된 자료형을 추출하려하면 fail 상태가 true가 된다.
        -   ```cpp
            int num
            cin >> num; // 입력이 숫자가 아니라면 fail 상태가 true가 된다.
            ```
    -   clear는 모든 스트림 상태를 정상으로 되돌린다.
    -   fail 상태가 true라면 >> 연산자는 아무것도 하지 않는다. (읽으려고 해도 아무 것도 읽지 않는다.) 따라서 무언가 작업을 하려면 clear를 하여 상태를 초기화해야 한다.
    -   eof를 만나면 eof 상태도 true고 fail상태도 true다.
    -   eof 처리를 잘못하면 무한 루프에 빠지기 쉽다.

-   실수 하기 쉬우니까 각자 stream reader 객체 만들어서 재사용해라.
    -   stream reader 객체에 필요한 테스트 케이스들에 대해 imgs/private/stream_test_case.png 참고

### seek, indicator

-   indicator 위치 파악

    -   [tellp](https://en.cppreference.com/w/cpp/io/basic_ostream/tellp) : returns the output position indicator
        -   p = put
        -   output stream인 경우 존재하는 메서드
    -   [tellg](https://en.cppreference.com/w/cpp/io/basic_istream/tellg) : returns the input position indicator
        -   g = get
        -   input stream인 경우 존재하는 메서드

-   indicator를 이동시키기

    -   [seekp](https://en.cppreference.com/w/cpp/io/basic_ostream/seekp) : p니 출력용
    -   [seekg](https://en.cppreference.com/w/cpp/io/basic_istream/seekg) : g니 입력용

-   이동 방식

    -   절대적 이동
        -   seekp(0) -> 출력 지시자 처음으로 이동
        -   seekg(10) -> 입력 지시자 10번째로 이동
    -   상대적 탐색 방식 ([seekdir](https://en.cppreference.com/w/cpp/io/ios_base/seekdir))

                -   ios::beg
                    beg the beginning of a stream
                    indicator를 처음으로 이동
                    seekp(3, ios::beg). 처음으로부터 3칸 뒤로
                -   ios::cur
                    cur the current position of stream position indicator
                    현재 indicator를 -> 방향(뒤)으로 이동
                    seekp(3, ios::cur). 현 지시자로부터 3칸 뒤로
                -   ios::end
                    end the ending of a stream
                    indicator를 마지막으로 이동
                    seekp(-6, ios:end). 마지막으로 부터 앞으로 6칸

## class

-   상태에 대해 멤버 변수 접두사 m을 붙일 것.
    -   로컬 변수인가 멤버 변수인가 구분이 편해짐
-   접근 제어자 public, protected, private
    -   기본 modifier는 private. 접근 제어자 작성하지 않으면 private.
    -   private는 해당 클래스 내에서만 접근 가능
    -   protected는 자식 클래스에서도 접근 가능
-   cpp 에선 stack, heap 어디든 인스턴스를 생성할 수 있지만 타 언어에선 일반적인 휴리스틱으로, 클래스를 통해 인스턴스를 생성하면 그것이 heap에 할당될 것이라고 여겨짐.
-   인스턴스 생성시 대입 말고 초기화 리스트(initializer list)를 사용하라.

-   `소멸자`

    -   heap에 할당된 객체 삭제해야 함. stack에 생성된 객체는 해당 스코프 벗어날 때 자동으로 소멸함.
    -
    -   new로 선언한 건 heap에 할당되므로 반드시 delete할 것

-   `const method`
    해당 클래스로 생성된 인스턴스 내의 멤버 변수를 바꾸지 않음을 의미.

-   `복사 생성자`

    -   타 언어에서의 clone, .copy와 같은 작업을 생성자 단에서 지원.
    -   class (const class&); 꼴.
    -   같은 클래스에 속한 객체를 활용해 새로운 객체를 생성하기.
    -   해당 복사 생성자가 없어도 컴파일러에서 그대로 넣어줌. (암시적 복사 생성자)

-   `암시적 복사 생성자`

    -   코드에 복사 생성자가 없으면 컴파일러가 알아서 넣어줌. 단 세부 멤버 변수 조작은 못하고 그대로 copy되는 동작만 함.
    -   암시적 복사 생성자는 `얕은 복사(shallow copy)`만 함.
        -   얕은 복사이므로 포인터형 변수들은 주소가 복사되어 mutate가 원본에도 영향을 미치게 되며
        -   원본 혹은 복사본이 삭제되고 메모리 정리를 하면 같은 메모리를 가리키고 있던 곳들은 전부 사용 불가능이 됨.
        -   여러모로 포인터 변수를 클래스가 가지고 있다면 `복사 생성자에서 깊은 복사를 직접 구현하는 것이 안전함.`

-   overloading

    -   이름과 반환형이 같고 매개변수가 다른 함수들.
    -   이름이 같은데 반환형이 다르면 컴파일 에러
        -   functions that differ only in their return type cannot be overloaded
    -   가장 적합한 함수를 찾아 호출하게 되는데, 이 과정을 `overload resolution`이라고 함.
        -   알아서 캐스팅 하는 등 없으면 알아서 찾으려고 하긴 하는데 처음부터 매개변수 잘 넣어 모호한 호출을 피하는게 좋다.
        -   어... 굳이 막 외울 필요는 없을 듯.

-   operator overloading

    -   python에서 \_\_eq\_\_, \_\_add\_\_ 등의 메서드를 오버로딩하는 것과 비슷한 개념.
    -   unary, binary operator 모두 가능
    -   정의한 class 내 지원하지 않는 operator(예를 들면 operator<<)는 전역 함수로 overload한 다음에 friend 선언을 통해 작업해야 함.
    -   복사생성자를 구현했다면 operator= overload도 해야 한다 (하단 rule of three 참고)

-   friend
    -   클래스 정의 안에 friend 키워드를 사용 가능
    -   다른 클래스나 함수가 private, protected 멤버에 접근할 수 있게 됨.
    -   friend는 함수도, 객체도 가능함.

### class에 암시적으로 정의되는 것들

-   매개변수 없는 constructor(default constructor)
    -   커스텀 constructor 정의시 암시적으로 정의되지 않음.
-   copy constructor (class(const class& other))
    -   암시적 copy constructor는 shallow copy만 함.
-   destructor (~class)
    -   heap 할당 객체 메모리 정리에 유의.
-   대입 연산자 = (copy assignment operator)

보통 하나를 정의하면 나머지도 다 정의해야 함(하단 rule of three 참고)

#### new/delete와 malloc()/free()의 차이?

new/delete는 할당/해제 + 생성자 및 소멸자를 호출.  
python으로 치면 `__new__`와 `__del__`이 호출됨.

malloc과 free는 오로지 메모리만을 할당/해제.

#### struct와 class의 차이?

'차이 없음'

1. 있따면, 기본 멤버가 public(struct)인가 private(class)인가
2. 어셈블리로 까봐도 차이가 없다.
3. cpp에서 생성, 소멸자, 메서드 등은 class 고유한 것이 아닌 struct도 가지고 있는 기능.

그러나, struct는 C처럼 쓰기를 권장한다. (plain old data).
struct에 생성, 소멸자, 메서드 할 수 있지만 하지 말자.
순수하게 데이터만을 담아두자. 이래야 memcpy() 등 메모리 조작이 편안해진다.

## class 상속

부모(베이스) - 자식(파생) 관계
is a 관계
Animal - Dog (Dog is a Animal)

파생 클래스는 베이스 클래스의 멤버 변수, 멤버 메서드를 가짐.

### 생성자, 소멸자 호출 순서

-   명시적이든 암시적이든 베이스 클래스의 생성자가 먼저 호출. 그 다음에 자식 클래스의 생성자 호출.
    -   따라서 상속시 메모리에서 부모 클래스가 먼저 초기화됨.
-   소멸자는 반대로 자식 소멸자가 먼저 호출한 후 베이스 클래스의 소멸자 자동 호출.

### 클래스와 메모리 레이아웃

-   기본적인 클래스의 메모리 레이아웃
    [image](../imgs/private/클래스의메모리레이아웃.png)

-   베이스 클래스와 자식 클래스의 멤버 변수들의 메모리 레이아웃
    [images](../imgs/private/상속의메모리레이아웃.png)

-   클래스의 멤버 함수들은 메모리 어디에?
    -   각 개체마다 잡히지 않음. 함수 동작은 어차피 똑같으므로 그런 방식은 메모리 낭비임.
    -   대신, `멤버 함수는 컴파일시 딱 한 번만 메모리에 할당됨`
    -   저수준에서 전역 함수와 그다지 다르지 않음

### 접근 제어 상속

파생 클래스는 상속시 베이스 클래스의 멤버에 대한 최저 접근 수준을 제어할 수 있음. 다만 public 상속이 대부분임.

```cpp
// public 상속. 베이스 클래스의 접근 제어가 그대로 유지됨.
// base : public -> derived : public
// base : protected -> derived : protected
// base : private -> derived : private
class Cat : public Animal {};

// protected 상속. public 접근이 불가해짐.
// base : public -> derived : protected
// base : protected -> derived : protected
// base : private -> derived : private
class Linux : protected OS {};

// private 상속. 모든 접근이 private이 됨.
// base : public -> derived : private
// base : protected -> derived : private
// base : private -> derived : private
class Honda : private Car {};
```

### 다중 상속은 안티패턴.

java, c#은 다중 상속을 금지함.
c++, python , scala는 다중 상속을 허용함.

python은 다이아몬드 문제 때문에 MRO 개념도 생기고 여러 문제점이 생기는 고로 추천하지 않는 패턴.

c++에선 다이아몬드 문제를 가상 베이스 클래스를 통해 해결하고자 함.
상속 받을 때 virtual을 명시하는 것임.
어... 굳이 기억할 필요가 있을까?

```cpp
class Cat: virtual public Animal;
class Dog: virtual public Animal;
```

### 추상 클래스(abstract class)와 순수 가상 함수(pure virtual function)

abstract 키워드 같은게 없다.  
`순수 가상 함수를 가지고 있는 base 클래스가 곧 추상 클래스다.`  
순수 가상 함수 = 구현이 없는 virtual 함수

추상 클래스로는 개체를 만들 수 없음.

### interface

c++에서 인터페이스 없음. 순수 가상 함수를 통해 흉내만 낼 수 있음.

만약 상속 받았음에도 구현하지 않으면
unimplemented pure virtual method 에러를 받는 등 interface의 의도된 동작은 하는 편.

## 다형성

`동일한 메서드를 사용했을 때 객체의 타입에 따라 다르게 응답할 수 있는 능력`

### 정적 바인딩(컴파일 바인딩) = 적은 대로 행한다.

-   정적 바인딩(컴파일 바인딩) : 컴파일 시간에 결정되는 바인딩. '무늬를 따라감'

```cpp
Base* cat = new Derived(5, "pepe");
Base* yourCat = new Derived(7, "juju");

cat->Speak();     // cat의 Speak이 호출됨
yourCat->Speak(); // animal의 Speak이 호출됨.
```

### 동적 바인딩(런타임 바인딩) = 가상 함수(virtual)로 실질을 런타임에 찾아 호출하도록 한다.

-   동적 바인딩(런타임 바인딩) = 가상 함수(virtual) 작성.
    -   실행 중에 어떤 함수를 호출할 것인지 결정됨. 따라서 런타임 바인딩.
    -   런타임 바인딩을 위하여 virtual function을 선언해야 함. 베이스 클래스에 가상 함수를 선언하면 자식 클래스의 가상 함수가 호출됨.
    -   이를 위해 `가상 테이블`이 생성됨.
        -   함수가 한 번만 메모리에 할당되어 사용되는 것 처럼 가상 함수를 찾기 위한 가상 테이블 또한 개체마다 생성되는 것이 아니라 클래스마다 하나씩 생성됨.
    -   가상 함수는 느림. 왜? 가상 테이블 가서 찾아야 하거든.

```cpp
class Animal {
public:
    // 실제 함수가 아님. 자식 함수에 의해 override됨.
    // 런타임에 실체를 찾아 실행되게끔 하라.
    virtual void Speak() { cout << "Animal" << endl; }
};
```

### 가상 소멸자

`모든 소멸자는 가상 소멸자로 작성하는 것이 좋다`  
`모든 소멸자에 virtual을 붙일 것`

```cpp
Base* a = new Derived(); // 정적 바인딩에 따르면 Base의 멤버 함수와 소멸자만 호출됨.
```

정적 바인딩에 따라 소멸자가 호출될 때 Derived의 소멸자가 호출되지 않음. -> 메모리 누수 발생.

따라서 소멸자에는 가급적 `virtual` 키워드를 명시하는 것이 좋음.
설사 Base 클래스가 아니더라도 해당 클래스가 이후에 Base 클래스가 될 경우도 고려하여 virtual 명시할 것.

## RAII(자원 획득은 초기화, resource acquisition is initialization)

## The rule of three/five/zero

cpp에서 class에 암시적으로 만들어주는게 많다보니...

[The rule of three/five/zero](https://en.cppreference.com/w/cpp/language/rule_of_three)

-   rule of three

    -   [destructor](https://en.cppreference.com/w/cpp/language/destructor)(소멸자), [copy constructor](https://en.cppreference.com/w/cpp/language/copy_constructor)(복사 생성자), [copy assignment operator](https://en.cppreference.com/w/cpp/language/copy_assignment)(대입 연산자 오버로드) 3개 중 하나를 구현했다면 보통 다른 2개도 같이 구현해야 한다.
    -   [예시](../109_oop_2/rule_of_three.cpp)

-   rule of five(C+11)

    -   위의 rule of three에 얹어서 2개 더 구현해야 함
    -   [move constructor](https://en.cppreference.com/w/cpp/language/move_constructor)
    -   [move assignment operator](https://en.cppreference.com/w/cpp/language/move_assignment)

```cpp
class MyClass {
public:
    MyClass(); // constructor
    ~MyClass(); // destructor

    MyClass(const MyClass&) = default; // 복사 생성자 (copy constructor)
    MyClass& operator=(const MyClass&) = default; // 복사 대입 연산자 (Copy Assignment Operator)

    MyClass& operator=(MyClass&&) = default; // 이동 대입 연산자(move assignment operator)
    MyClass(MyClass&&) = default; // 이동 생성자(move constructor)
};
```

-   rule fo zero
    -   힘들지? 객체가 자원을 직접 관리하지 않고, 대신에 자원 관리를 스마트 포인터, 표준 라이브러리의 컨테이너, RAII(Resource Acquisition Is Initialization) 등을 통해 자동으로 처리하도록 .

## etc

### c의 헤더를 써도 되나?

된다. 하지 말라는 사람도 있는데 성능 상 이유로 c 헤더 그냥 쓰는 곳도 많다.

<string.h> -> <cstring>
<stdio.h> -> <cstdio>
<ctype.h> -> <cctype>
<math.h> -> <cmath>

### string + string slow. why?

동적인 길이를 가진 string이라면
특정 길이보다 넘어간다면 malloc 새로 해줘야할텐데
heap에 데이터 할당하는 작업이 overhead로 들어갈 수밖에 없음. 애초에 힙 할당이 느림. 즉, stack에 정적으로 문자 배열 100개 깔아 놓고 시작하는 것에 비해 느림.
길이가 가변되는 동적 문자열의 string + string은 느릴 수 밖에 없다.
또한, 내부 버퍼 증가는 멀티 스레드 환경에서 안전하지 않을 수도 있다.
그 결과,
아직도 정해진 길이의 문자 배열 선언한 다음에 sprintf로 쓰는 작업을 C++에서도 자주함.
