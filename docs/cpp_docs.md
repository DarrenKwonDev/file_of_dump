<!-- toc -->

-   [cpp_docs](#cpp_docs)
    -   [권고 사항](#%EA%B6%8C%EA%B3%A0-%EC%82%AC%ED%95%AD)
    -   [version](#version)
    -   [compiler](#compiler)
    -   [stream input/output](#stream-inputoutput)
        -   [stream 종류](#stream-%EC%A2%85%EB%A5%98)
        -   [stream state](#stream-state)
        -   [seek, indicator](#seek-indicator)
    -   [explicit casting (명시적 캐스팅)](#explicit-casting-%EB%AA%85%EC%8B%9C%EC%A0%81-%EC%BA%90%EC%8A%A4%ED%8C%85)
    -   [class](#class)
        -   [class에 암시적으로 정의되는 것들](#class%EC%97%90-%EC%95%94%EC%8B%9C%EC%A0%81%EC%9C%BC%EB%A1%9C-%EC%A0%95%EC%9D%98%EB%90%98%EB%8A%94-%EA%B2%83%EB%93%A4)
        -   [The rule of three/five/zero](#the-rule-of-threefivezero)
            -   [new/delete와 malloc()/free()의 차이?](#newdelete%EC%99%80-mallocfree%EC%9D%98-%EC%B0%A8%EC%9D%B4)
            -   [struct와 class의 차이?](#struct%EC%99%80-class%EC%9D%98-%EC%B0%A8%EC%9D%B4)
    -   [class 상속](#class-%EC%83%81%EC%86%8D)
        -   [생성자, 소멸자 호출 순서](#%EC%83%9D%EC%84%B1%EC%9E%90-%EC%86%8C%EB%A9%B8%EC%9E%90-%ED%98%B8%EC%B6%9C-%EC%88%9C%EC%84%9C)
        -   [클래스와 메모리 레이아웃](#%ED%81%B4%EB%9E%98%EC%8A%A4%EC%99%80-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EB%A0%88%EC%9D%B4%EC%95%84%EC%9B%83)
        -   [접근 제어 상속](#%EC%A0%91%EA%B7%BC-%EC%A0%9C%EC%96%B4-%EC%83%81%EC%86%8D)
        -   [다중 상속은 안티패턴.](#%EB%8B%A4%EC%A4%91-%EC%83%81%EC%86%8D%EC%9D%80-%EC%95%88%ED%8B%B0%ED%8C%A8%ED%84%B4)
        -   [추상 클래스(abstract class)와 순수 가상 함수(pure virtual function)](#%EC%B6%94%EC%83%81-%ED%81%B4%EB%9E%98%EC%8A%A4abstract-class%EC%99%80-%EC%88%9C%EC%88%98-%EA%B0%80%EC%83%81-%ED%95%A8%EC%88%98pure-virtual-function)
        -   [interface](#interface)
    -   [다형성](#%EB%8B%A4%ED%98%95%EC%84%B1)
        -   [정적 바인딩(컴파일 바인딩) = 적은 대로 행한다.](#%EC%A0%95%EC%A0%81-%EB%B0%94%EC%9D%B8%EB%94%A9%EC%BB%B4%ED%8C%8C%EC%9D%BC-%EB%B0%94%EC%9D%B8%EB%94%A9--%EC%A0%81%EC%9D%80-%EB%8C%80%EB%A1%9C-%ED%96%89%ED%95%9C%EB%8B%A4)
        -   [동적 바인딩(런타임 바인딩) = 가상 함수(virtual)로 실질을 런타임에 찾아 호출하도록 한다.](#%EB%8F%99%EC%A0%81-%EB%B0%94%EC%9D%B8%EB%94%A9%EB%9F%B0%ED%83%80%EC%9E%84-%EB%B0%94%EC%9D%B8%EB%94%A9--%EA%B0%80%EC%83%81-%ED%95%A8%EC%88%98virtual%EB%A1%9C-%EC%8B%A4%EC%A7%88%EC%9D%84-%EB%9F%B0%ED%83%80%EC%9E%84%EC%97%90-%EC%B0%BE%EC%95%84-%ED%98%B8%EC%B6%9C%ED%95%98%EB%8F%84%EB%A1%9D-%ED%95%9C%EB%8B%A4)
        -   [그래서 virtual을 왜 쓰냐?](#%EA%B7%B8%EB%9E%98%EC%84%9C-virtual%EC%9D%84-%EC%99%9C-%EC%93%B0%EB%83%90)
        -   [가상 소멸자](#%EA%B0%80%EC%83%81-%EC%86%8C%EB%A9%B8%EC%9E%90)
    -   [inline function](#inline-function)
    -   [static = 범위의 제한을 받는 전역 변수](#static--%EB%B2%94%EC%9C%84%EC%9D%98-%EC%A0%9C%ED%95%9C%EC%9D%84-%EB%B0%9B%EB%8A%94-%EC%A0%84%EC%97%AD-%EB%B3%80%EC%88%98)
    -   [exceptions](#exceptions)
        -   [cpp에서의 exception](#cpp%EC%97%90%EC%84%9C%EC%9D%98-exception)
        -   [os exception != cpp exception](#os-exception--cpp-exception)
        -   [예외 안전성(exception-safety)](#%EC%98%88%EC%99%B8-%EC%95%88%EC%A0%84%EC%84%B1exception-safety)
    -   [template programming](#template-programming)
    -   [template class linking error](#template-class-linking-error)
        -   [언제 template을 사용하면 좋나요](#%EC%96%B8%EC%A0%9C-template%EC%9D%84-%EC%82%AC%EC%9A%A9%ED%95%98%EB%A9%B4-%EC%A2%8B%EB%82%98%EC%9A%94)
        -   [generic과 무슨 차이가 있나요 = compile time polymorphism](#generic%EA%B3%BC-%EB%AC%B4%EC%8A%A8-%EC%B0%A8%EC%9D%B4%EA%B0%80-%EC%9E%88%EB%82%98%EC%9A%94--compile-time-polymorphism)
    -   [C++11](#c11)
        -   [auto (C++11)](#auto-c11)
        -   [static_assert (C++11)](#static_assert-c11)
        -   [default/delete (C++11)](#defaultdelete-c11)
        -   [final/override (C++11)](#finaloverride-c11)
        -   [nullptr (C++11)](#nullptr-c11)
        -   [fixed width integer type (C++11)](#fixed-width-integer-type-c11)
        -   [enum class (C++11)](#enum-class-c11)
        -   [범위 기반 for문 (C+11)](#%EB%B2%94%EC%9C%84-%EA%B8%B0%EB%B0%98-for%EB%AC%B8-c11)
    -   [smart pointer (C+11)](#smart-pointer-c11)
        -   [unique_ptr (C++11)](#unique_ptr-c11)
            -   [make_unique (C++14)](#make_unique-c14)
        -   [shared_ptr (C++11)](#shared_ptr-c11)
            -   [자동 메모리 관리](#%EC%9E%90%EB%8F%99-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EA%B4%80%EB%A6%AC)
        -   [weak_ptr (C++11)](#weak_ptr-c11)
            -   [강한 참조와 약한 참조](#%EA%B0%95%ED%95%9C-%EC%B0%B8%EC%A1%B0%EC%99%80-%EC%95%BD%ED%95%9C-%EC%B0%B8%EC%A1%B0)
    -   [etc](#etc)
        -   [RAII(자원 획득은 초기화, resource acquisition is initialization)](#raii%EC%9E%90%EC%9B%90-%ED%9A%8D%EB%93%9D%EC%9D%80-%EC%B4%88%EA%B8%B0%ED%99%94-resource-acquisition-is-initialization)
        -   [c의 헤더를 써도 되나?](#c%EC%9D%98-%ED%97%A4%EB%8D%94%EB%A5%BC-%EC%8D%A8%EB%8F%84-%EB%90%98%EB%82%98)
        -   [string + string slow. why?](#string--string-slow-why)

<!-- tocstop -->

# cpp_docs

## 권고 사항

-   delete

    -   delete로 지울 수 있는 건 heap 할당된 객체 뿐임.
    -   new로 객체 선언한 건 heap에 할당되니 반드시 delete할 것. 배열은 delete[]로 삭제.
    -   stl container 등에 객체의 포인터형을 저장했다면, 해당 container를 사용 후에는 모든 원소에 대해서 메모리 정리를 해주어야 함. (114_stl_container/vector/ptr_vector_heap_cleanup.cpp) 참고

-   class

    -   모든 소멸자는 가상 소멸자로 작성하는 것이 좋다
    -   rule of three(five) / zero
    -   `클래스의  멤버 함수는 컴파일시 딱 한 번만 메모리에 할당됨`. 저수준에서 전역 함수와 그다지 다르지 않음. 개체마다 멤버 함수가 메모리에 위치한다면 상당한 공간 낭비.
    -   c++11의 override는 부모가 가상함수라는점 + 가상 함수를 바르게 오버라이드했다라는 것을 보장하는 효과가 있기 때문에 가능하면 사용하자.

-   struct

    -   struct는 C처럼 쓰기를 권장한다. (plain old data).
        struct에 생성, 소멸자, 메서드 할 수 있지만 하지 말자.
        순수하게 데이터만을 담아두자. 이래야 memcpy() 등 메모리 조작이 편안해진다.

-   enum
    컴파일러는 열거형 상수를 정수 값으로 대체하여 컴파일된 코드에 포함시킵니다. 일종의 #define과 같이 작동하는 것.

        ```cpp
        class MyIntArray {
            public:
            bool Add(int data);
            MyIntArray(){};

        private:
        // 1이 선호되는 편.
        // case 1. enum { MAX = 3 };
        // case 2. static const int MAX = 3;
            int mSize;
            int mArray[MAX];
        };
        ```

-   어셈블리 까보면 reference나 pointer나 같다. 다만 언어적 차원에서 reference가 좀 더 안전하게 쓰기 위해 만들어진 것. 많이 쓰자.

-   auto

    -   최대한 가독성 있게 적자. auto, auto\*, auto&를 구분하여 해당 변수가 값인지, 포인터인지, 참조인지를 구분할 수 있도록 하자.
    -   ::iterator, 이름이 긴 클래스 생성자 등을 auto로 선언하면 편리하다.

-   읽기 전용 매개변수는 상수 참조로, 출력용 매개변수는 포인터로.

    -   func(int\* a, const int b, const int c)
    -   func(&a, b, c)

-   C와 Cpp간의 확장자는 분리하여 적을 것

    -   c : `*.c`
    -   cpp: `*.cpp`, `*.cc`, `*.cxx`
    -   `*.h` vs`*.hpp`
        -   https://stackoverflow.com/questions/152555/h-or-hpp-for-your-class-definitions
        -   .h : C/C++ compatible or pure C Headers
        -   .hpp : C++ Headers
    -   `.inl`: 인라인 함수를 포함하는 C++ 헤더 파일을 위한 확장자, 주로 템플릿 구현에 사용됩니다.

## version

C++98 (최초 표준 버전)  
C++03

이후 8년만에 새 버전이 등장하고 매 3년마다 갱신됨.  
특히 C++11에 도입된 기능은 현재까지도 유의미하게 사용되는 것이 많음.

C++11/14/17/20...

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

## explicit casting (명시적 캐스팅)

[c style casting](https://en.cppreference.com/w/cpp/language/explicit_cast)의 작업을 4가지로 분류하여 좀 더 세밀한 캐스팅을 할 수 있게 함.

다만, 대부분 static_cast를 사용하고, 특수한 경우에만 다른 cast를 사용함.

-   [static_cast](https://en.cppreference.com/w/cpp/language/static_cast)

    -   converts one type to another related type
    -   호환되지 않는 형으로 캐스팅하더라도 컴파일 시간에만 검사되며, 런타임에는 검사되지 않아 터지진 않음. 즉, 캐스팅이 실제로 유효한지 여부를 확인하지 않습니다

-   reinterpret_cast

    -   converts type to unrelated type
    -   연관 없는 형 사이의 변환.

-   const_cast

    -   adds or removes cv-qualifiers
    -   형을 바꿀 순 없음. 형을 바꾸려하면 compile error.
    -   const, volatile를 제거할 때만 사용함.
    -   웬만하면 안티패턴임. const로 선언되어 있는 포인터를 아닌 것으로 변환하다니. 다만 서드파티 코드를 입맛대로 개조할 때는 종종 사용함.

-   dynamic_cast(C++98, modern C++)
    -   converts within inheritance hierarchies
    -   호환되지 않는 자식형으로 캐스팅하면 NULL을 반환함. 잘못된 형 변환도 일단 컴파일하고 보는 static_cast보다 안전한 편임.
    -   그런데 이걸 사용하려면 컴파일 옵션 중 RTTI(real time type information)를 켜야 함. 그렇지 않다면 static_cast와 동일하게 작동함.
    -   RTTI 기능을 켜면 성능 저하가 일어나기 때문에 아직 적극적 사용은 요원함.

## class

-   상태에 대해 멤버 변수 접두사 m을 붙일 것.
    -   로컬 변수인가 멤버 변수인가 구분이 편해짐
-   접근 제어자 public, protected, private
    -   기본 modifier는 private. 접근 제어자 작성하지 않으면 private.
    -   private는 해당 클래스 내에서만 접근 가능
    -   protected는 자식 클래스에서도 접근 가능
-   cpp 에선 stack, heap 어디든 인스턴스를 생성할 수 있지만 타 언어에선 일반적인 휴리스틱으로, 클래스를 통해 인스턴스를 생성하면 그것이 heap에 할당될 것이라고 여겨짐.
-   인스턴스 생성시 대입 말고 초기화 리스트(initializer list)를 사용하라.

-   `생성자`

    ```cpp
    // stack에 할당. (빠름)
    Vec a;          // 직접 Vec 객체 생성 (복사를 하지 않으므로 이 방법이 권장됨
    Vec aa = Vec(); // Vec 객체를 생성 후 복사함. (비추천. 굳이 복사 한 번 더 해야 함.)

    // heap에 할당. (느림)
    // 정확히는 Vec* 즉, 포인터 변수 b는 stack에 존재하지만
    // 실제 데이터(int 2개인 mX, mY 각 4byte)는 heap에 존재함.
    Vec* b = new Vec();

    delete b; // heap에 할당된 객체는 반드시 delete 해야 함.
    ```

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

### The rule of three/five/zero

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
    MyClass() = default; // constructor
    ~MyClass() = default; // destructor

    MyClass(const MyClass&) = default; // 복사 생성자 (copy constructor)
    MyClass& operator=(const MyClass&) = default; // 복사 대입 연산자 (Copy Assignment Operator)

    MyClass& operator=(MyClass&&) = default; // 이동 대입 연산자(move assignment operator)
    MyClass(MyClass&&) = default; // 이동 생성자(move constructor)
};
```

-   rule fo zero
    -   힘들지? 객체가 자원을 직접 관리하지 않고, 대신에 자원 관리를 스마트 포인터, 표준 라이브러리의 컨테이너, RAII(Resource Acquisition Is Initialization) 등을 통해 자동으로 처리하도록 .

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
`virtual (return) func(param) = 0` 꼴의 형태.

추상 클래스로는 개체를 만들 수 없음.

### interface

c++에서 인터페이스 없음. 순수 가상 함수를 통해 흉내만 낼 수 있음.

만약 상속 받았음에도 구현하지 않으면
unimplemented pure virtual method 에러를 받는 등 interface의 의도된 동작은 하는 편.

## 다형성

`동일한 메서드를 사용했을 때 런타임에 객체의 타입에 따라 다르게 응답할 수 있는 능력`

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

### 그래서 virtual을 왜 쓰냐?

일반함수의 override는 정적 바인딩(선언을 따라감)
virtual 함수의 override는 동적 바인딩(실질을 따라감)

### 가상 소멸자

`모든 소멸자는 가상 소멸자로 작성하는 것이 좋다`  
`모든 소멸자에 virtual을 붙일 것`

```cpp
Base* a = new Derived(); // 정적 바인딩에 따르면 Base의 멤버 함수와 소멸자만 호출됨.
```

정적 바인딩에 따라 소멸자가 호출될 때 Derived의 소멸자가 호출되지 않음. -> 메모리 누수 발생.

따라서 소멸자에는 가급적 `virtual` 키워드를 명시하는 것이 좋음.
설사 Base 클래스가 아니더라도 해당 클래스가 이후에 Base 클래스가 될 경우도 고려하여 virtual 명시할 것.

## inline function

단순한데 함수 호출에 의한 오버헤드를 가져가기 싫을 때.
특히 함수를 만드는 가독성의 이점에 비해 오버헤드가 더 클 것 같을 때.

inline 함수를 선언하면 컴파일러가 함수 호출이 아닌 복붙으로 대체함.
마치 매크로 같이 작동함.

다만 C와 마찬가지로 inline은 힌트일 뿐이며, 컴파일러가 inline으로 대체할지 말지는 컴파일러의 몫이다. inline 키워드를 사용하더라도 꼭 인라인 함수가 되지는 않는다. (컴파일러 마음대로~) inline 키워드를 사용하지 않더라도 컴파일러가 인라인 함수로 만들 수도 있다.

## static = 범위의 제한을 받는 전역 변수

범위는 어디?  
파일 / 네임스페이스 / 클래스 / 함수

메모리에 따로 잡히며 전역 변수 처럼 동작한다고 보면 된다.

-   case 1. 함수 내 정적 변수

    -   해당 함수 내에서 최초로 한 번 초기화 되며 재호출되어도 재할당되지 않고 값을 유지함.

-   case 2. 클래스 내 정적 멤버 변수

    -   클래스당 단 하나의 copy만 존재. 즉, 개체당 존재하지 않으면 클래스에 하나만 존재함. (타 언어에서 클래스에 static 변수 선언한 것과 동일함)
    -   정적(static) 멤버 변수를 선언할 때는 클래스 외부에서 해당 변수를 초기화해야 합니다.

-   case 3. 클래스 내 정적 함수
    -   타 언어와 마찬가지로 클래스에서 호출 가능한 정적 함수. 메모리에서 한 번만 할당되어 클래스의 모든 개체가 공유함.
    -   정적 함수는 해당 클래스의 정적 멤버 변수만 접근 가능함. 당연함. 전 클래스가 공유하고 있으므로.

## exceptions

### cpp에서의 exception

> 결론부터 말하자면 감당할 수 없는 예외는 함부러 잡지말고 그냥 죽게 내버려두자.
> 출처 : https://medium.com/@jngbng/c-%EC%98%88%EC%99%B8-%EC%9E%A1%EC%95%84%EC%95%BC%ED%95%98%EB%82%98-%EB%A7%90%EC%95%84%EC%95%BC-%ED%95%98%EB%82%98-a2637169a5d4

1. exception 남용 금지

내가 대응할 수 없는 사실에 대해서만 exception 처리해야 함.  
경계에서 외부 데이터와 통신할 때  
파일을 읽어올 때 등 보통 외부 시스템과의 경계에서 exception이 발생할 수 있음.

exception을 던지지 않아도 해결가능함에도 exception을 남용하는 경우가 많음

예를 들어,
out of range는 길이는 직접 검사하거나
null pointer exception은 포인터가 null인지 검사하거나
0으로 나누는 예외는 예외를 던지기보다 미리 검사하는 방식으로 해결 가능하다.

2. try/catch의 오버헤드

try/catch 구문의 disassembly를 살펴보면, 양이 꽤 많음. exception handling은 무료가 아님. (https://godbolt.org/) 와 같은 사이트에서 disassembly를 살펴보면 알 수 있음. exception은 부하가 있다고 생각하자.

3. 예외 처리 할 거면 왜 성능 중요한 cpp을 쓰는가.

cpp 쓴다면 perf가 critical 한 분야일텐데 왜 쓰는가.

(단, 생성자 예외는 exception으로 처리하는 것이 바람직하다.)
(custom_exception.cpp 참고) 다만 이 경우에도 생성자에서 예외를 발생시키는 경우면 보통 할당 실패인데 이 경우에는 차라리 프로그램을 종료하는게 낫다. exception이 필요한 레벨이면 굳이 Cpp을 쓸 필요가 없다. 여러모로 cpp에서는 exception이 잘 쓰이지 않음.

4. 함수가 발생시키는 exception을 알기 힘들고 제대로 다루기도 힘듦.

코드를 직접 읽어보는 방법 뿐.
그리고 함수 내부에 함수를 호출하는 경우 콜스택을 거슬러 올라가서 찾아야 함.
문제가 복잡해질 수 있음.
(java는 예외. 헤더에 예외 종류가 보임.)

타 언어 쓸 때도 알겠지만 특정한 exception을 잡기보다 catch문에서 발생할 수 있는 모든 종류의 exception을 잡아버리는 코딩 스타일을 쓰는데 이는 제대로 exception 처리하기가 빡셈을 의미함.

### os exception != cpp exception

-   os exception

    -   비동기적 (언어 내에서 os에서 exception을 받아야 하므로 비동기적 동작)
    -   POSIX signal, faults, traps, aborts
    -   플랫폼마다 다름
    -   오버헤드가 비교적 큼

-   cpp exception
    -   동기적 (언어 내부에서 처리)
    -   C++ STL
    -   플랫폼에 상관없이 동일한 동작
    -   오버헤드가 비교적 적음

### 예외 안전성(exception-safety)

-   [예외 안전성](https://en.wikipedia.org/wiki/Exception_safety)

    -   exception이 throw되었을 때 정상적으로 코드가 동작함을 의미.
    -   exception safety의 단계 및 exception unsafe는 문서 참고 요망.
    -   일종의 transaction과 같이 예외 발생 전으로 복구하는 등의 기능이 필요한데 언어 레벨에서는 이런 개념이 없다. 그래서 알아서 코드를 예외 안전성을 가지도록 짜야 한다.

-   exception이 발생한 operation은 그대로 망가뜨리고, 대신 로깅 잘 찍고 (메모리 덤핑 떠서 송신하게끔 만드는 등) 다음 리퀘스트에 대해서는 정상적인 처리를 할 수 있는 정도로는 해둬야 한다.
-   결국, exception이 발생하면 이후의 작동을 보장할 수 없으니 여기서 프로그램이 멈추는게 맞다.

## template programming

compile time polymorphism을 구현할 수 있긴 하나 남용하면 가독성과 디버깅이 매우 힘들어짐.

## template class linking error

`C++에서 템플릿 클래스를 사용할 때, 템플릿 클래스의 선언과 정의를 분리하려면 일반적으로 템플릿 클래스의 정의를 헤더 파일에 넣어야 함.`

template class를 별도의 header, cpp 파일로 분리할 경우 컴파일 도중 cpp 파일을 알 수가 없음. (linking 과정 전이므로). inline 함수와 마찬가지로 template class의 구현을 header에 넣어야 함.

어.. 살펴보니 header만 정의하는 경우도 꽤 있는 듯?

### 언제 template을 사용하면 좋나요

container형 구조에는 적합.  
각기 다른 타입 3개 이상을 다뤄야 한다면 template 적합.

2개 정도만 다룬다면 함수, 클래스를 따로 만드는 등의 중복 코드를 작성하는게 나음.

### generic과 무슨 차이가 있나요 = compile time polymorphism

template은 실제 타입이 컴파일 시 결정됩니다.
정확히는, template을 인스턴스화할 때마다 컴파일러가 내부적으로 코드를 생성합니다.

반면 generic은 실제 데이터 타입이 런타임에 결정됩니다.

compile time에 코드를 생성하는 template의 특성으로 컴파일 시간이 늘어날 것입니다.

또한, template에 넣는 자료형 가짓수에 비례하여 실행 파일의 크기가 증가할 것입니다.

## C++11

### auto (C++11)

https://en.cppreference.com/w/cpp/language/auto

-   strong type 언어에서의 auto

    동적 타입이라고해서 js의 var, let 같이 런타임에 타입이 변경되는 것이 아니다.  
    C/Cpp는 컴파일 타임시에 타입이 정해져야 하는 strong type 언어이다. cpp의 auto는 단순히 컴파일 시점의 타입을 추론해주는 것이다.

-   auto에서의 포인터와 참조

    -   포인터형 : auto, auto\* (그러나 가독성을 위해 auto\* 권고)
    -   참조형 : auto& (&를 적지 않으면 참조형으로 받지 않는다. 반드시 적을 것.)
    -   const : const를 적지 않아도 이어 받으나 가독성을 위해 const auto, const auto\*, const auto& 사용 권고.
    -   결론적으로, 가급적 명시적으로 적어야 한다! const, \*, & 다 적자.

-   모든 것을 auto로 바르면 가독성이 안 좋아진다. auto를 쓰면 몇가지 좋은 경우에서만 쓰자.

    -   1. 반복자. 솔직히 ::iterator 손 아프자나
    -   2. 이름 긴 클래스의 인스턴스. auto로 쓰면 편함.

-   auto를 써도 런타임 성능은 동일함. 걱정 ㄴㄴ

### static_assert (C++11)

컴파일 시점에 assert가 가능하다.  
C11에서 사용하던 그것이 맞다.

### default/delete (C++11)

class에서 암시적 생성자 때문에 골치 아팠다.

-   매개변수 없는 constructor(default constructor)
-   copy constructor (class(const class& other))
-   destructor (~class)
-   대입 연산자 = (copy assignment operator)

default는 '컴파일러가 생성해준 기본 생성자, 소멸자, 연산자들을 사용하겠다'를 명시적으로 표현하는 것이다.

delete는 '컴파일러가 자동으로 만들어주지 않길 원한다'는 것을 명시적으로 표현하는 것이다.

default/delete 등장 전에는 수작업으로 다 구현하던가, 가구현하여 private으로 만들어 호출 자체를 숨겼었다.

```cpp
class MyClass {
public:
    MyClass() = default; // constructor
    ~MyClass() = default; // destructor

    MyClass(const MyClass&) = default; // 복사 생성자 (copy constructor)
    MyClass& operator=(const MyClass&) = default; // 복사 대입 연산자 (Copy Assignment Operator)

    MyClass& operator=(MyClass&&) = default; // 이동 대입 연산자(move assignment operator)
    MyClass(MyClass&&) = default; // 이동 생성자(move constructor)
};
```

### final/override (C++11)

해당 선언자들은 virtual function에서만 사용 가능하다.
final은 virtual function에서만 선언 가능하며
override는 override할 대상이 virtual function일 경우에만 가능하다.

final : 상속 안 할거야. 날 부모로 쓰지마.

    -   final class
    -   final function.

override : override 할거야.

    - 해당 함수가 부모의 virtual function을 override하는지 검사. 아니면 컴파일 에러.
    - 부모의 virtual function이 아닌 함수를 override 하려할 때도 에러.
    - 부모가 가상함수라는점 + 가상 함수를 바르게 오버라이드했다라는 것을 보장하는 효과가 있기 때문에 가능하면 사용하자.

### nullptr (C++11)

https://en.cppreference.com/w/cpp/language/nullptr

null ptr를 표현하는 자료형.

### fixed width integer type (C++11)

https://en.cppreference.com/w/cpp/types/integer

가급적 C+11 이상이 보장된다면 사용하자.

### enum class (C++11)

-   정수형으로의 암시적 캐스팅이 없음
-   enum의 원소에 할당할 바이트 지정.

### 범위 기반 for문 (C+11)

## smart pointer (C+11)

-   원시 포인터를 wrapping하여 원시 포인터의 소유권과 참조 횟수 기반으로 관리.
-   객체의 수명에 따라 메모리 관리를 자동으로 하는 효과. 스마트 포인터를 사용하면 delete를 직접 호출할 필요가 없다. GC보다도 빠르다.

### unique_ptr (C++11)

https://en.cppreference.com/w/cpp/memory/unique_ptr

-   특징
    원시 포인터 하나를 소유하고, 다른 것과 공유하지 않음.
    따라서 `복사나 대입이 불가능함.`

    unique_ptr를 사용할 경우 그 속에 있는 원시 포인터를 다른 unique_ptr에 넣을 수 없다.

-   언제 수거되나?
    scope를 벗어날 때 자동으로 지워짐.

-   언제 사용하면 좋나?
    (125_unique_ptr/unique_ptr_use_case.cpp 참고)
    1. 클래스 내 개체 선언. 개체 메모리 정리를 할 필요가 없어지므로.
    2. heap에 객체 할당할 때. delete로 지우는 것을 잊어도 안전함.
    3. 객체의 포인터를 담은 container 내부를 순회하며 정리하기 번거로울 때.

#### make_unique (C++14)

https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique

`make_unique<Class>(param)`

주어진 Class를 param과 함께 new 키워드로 호출 (즉, heap 할당됨)

### shared_ptr (C++11)

https://en.cppreference.com/w/cpp/memory/shared_ptr

#### 자동 메모리 관리

-   GC 방식
    Java, C#, Python, JavaScript (V8 엔진 등)  
    GC도 여러 종류가 존재하며 장단점이 있음.  
    [Java Garbage Collection의 종류](https://d2.naver.com/helloworld/1329)  
    [GC 일반](https://learn.microsoft.com/ko-kr/dotnet/standard/garbage-collection/fundamentals)

    -   stop-the-world
        memory leak을 막기 위해 주기적으로 메모리 검사를 함. 따라서 GC가 돌 때 애플리케이션이 버벅일 수 있음. 이런 현상은 stop-the-world 문제로 발생한다. 어떤 GC 알고리즘을 사용하더라도 stop-the-world는 발생한다. 실시간성이 중요한 경우에 GC로 도는 언어는 사용하기 어렵다.

-   ref count 방식
    Objective-C, Swift, COM(DirectX)  
    주로 C++의 std::shared_ptr와 같은 스마트 포인터를 통해 구현.

    -   GC에 비해 실시간성이 중요한 프로그램에 적합하나 ref count를 증가시키는 작업이 atomic하지 않기 때문에 lock을 거는 작업을 해야 함. 결국 원시 포인터보다는 느리다.

-   결론
    delete를 잊어버리는 등의 메모리 누수는 발생하지 않으나 trade-off가 있고, 순환 참조와 같은 상황에서는 메모리 누수가 여전히 발생할 수 있음. 여튼 완벽한 건 없음.

### weak_ptr (C++11)

#### 강한 참조와 약한 참조

약한 참조는 refCnt를 증가시키지 않음.

왜 약한 참조가 필요한가?

1. 참조 카운트는 너무 자주 바뀜. multi thread에서는 atomic 하지 않음.
2. 강한 참조만으로 순환 참조가 발생했을 때 refCnt가 0이 되지 않음.

## etc

### RAII(자원 획득은 초기화, resource acquisition is initialization)

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
