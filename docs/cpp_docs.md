<!-- toc -->

-   [cpp_docs](#cpp_docs)
    -   [권고 사항](#%EA%B6%8C%EA%B3%A0-%EC%82%AC%ED%95%AD)
    -   [c의 헤더를 써도 되나?](#c%EC%9D%98-%ED%97%A4%EB%8D%94%EB%A5%BC-%EC%8D%A8%EB%8F%84-%EB%90%98%EB%82%98)
    -   [string + string slow. why?](#string--string-slow-why)
    -   [compiler](#compiler)
    -   [stream input/output](#stream-inputoutput)
        -   [stream 종류](#stream-%EC%A2%85%EB%A5%98)
        -   [stream state](#stream-state)
        -   [seek, indicator](#seek-indicator)
    -   [class](#class)

<!-- tocstop -->

# cpp_docs

## 권고 사항

-   어셈블리 까보면 reference나 pointer나 같다. 다만 언어적 차원에서 reference가 좀 더 안전하게 쓰기 위해 만들어진 것. 많이 쓰자.
-   new로 객체 선언한 건 반드시 delete할 것. 객체 배열은 delete[]로 삭제.
-   읽기 전용 매개변수는 상수 참조로, 출력용 매개변수는 포인터로.
    -   func(int\* a, const int b, const int c)
    -   func(&a, b, c)

## c의 헤더를 써도 되나?

된다. 하지 말라는 사람도 있는데 성능 상 이유로 c 헤더 그냥 쓰는 곳도 많다.

<string.h> -> <cstring>
<stdio.h> -> <cstdio>
<ctype.h> -> <cctype>
<math.h> -> <cmath>

## string + string slow. why?

동적인 길이를 가진 string이라면
특정 길이보다 넘어간다면 malloc 새로 해줘야할텐데
heap에 데이터 할당하는 작업이 overhead로 들어갈 수밖에 없음. 애초에 힙 할당이 느림. 즉, stack에 정적으로 문자 배열 100개 깔아 놓고 시작하는 것에 비해 느림.
길이가 가변되는 동적 문자열의 string + string은 느릴 수 밖에 없다.
또한, 내부 버퍼 증가는 멀티 스레드 환경에서 안전하지 않을 수도 있다.
그 결과,
아직도 정해진 길이의 문자 배열 선언한 다음에 sprintf로 쓰는 작업을 C++에서도 자주함.

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
-   소멸자
    -   heap에 할당된 객체를 삭제해야 함. stack에 생성된 객체는 해당 스코프 벗어날 때 자동으로 소멸함.
    -   new로 선언한 건 heap에 할당되므로 반드시 delete할 것
    -   특히, 클래스 내부에서 동적 메모리 할당이 일어났으면 같이 소멸자에서 해제해줘야 함.
-   const method
    해당 클래스로 생성된 인스턴스 내의 멤버 변수를 바꾸지 않음을 의미.

### new/delete와 malloc()/free()의 차이?

new/delete는 할당/해제 + 생성자 및 소멸자를 호출.  
python으로 치면 `__new__`와 `__del__`이 호출됨.

malloc과 free는 오로지 메모리만을 할당/해제.

## RAII(자원 획득은 초기화, resource acquisition is initialization)
