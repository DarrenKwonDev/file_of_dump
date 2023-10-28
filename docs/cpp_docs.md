<!-- toc -->

-   [cpp_docs](#cpp_docs)
    -   [compiler](#compiler)
    -   [cmd, etc](#cmd-etc)

<!-- tocstop -->

# cpp_docs

## compiler

apple : llvm(low level virtual machine) 기반 clang/calng++, lldb
linux : gcc(GNU compiler collection) 기반 gcc/g++, gdb
window : msvc

## cmd, etc

```bash
nodemon --exec "clang++ -std=c++11 ./*.cpp && gtime -f '%P cpu \n%es exeuction time\nmomery %MKB' ./a.out" -e cpp
```

```bash
> size ./a.out

__TEXT  __DATA  __OBJC  others  dec     hex
16384   0       0       4295000064      4295016448      10000c000
```

\_\_TEXT: 프로그램 코드가 저장된 섹션의 크기를 나타냅니다. 이 섹션에는 프로그램의 실행 코드가 저장됩니다.

\_\_DATA: 초기화된 전역 변수 및 정적 변수가 저장된 섹션의 크기를 나타냅니다. 이 섹션에는 프로그램에서 직접 초기화한 변수들이 저장됩니다.

\_\_OBJC: Objective-C 코드 및 데이터가 저장된 섹션의 크기를 나타냅니다. 이 섹션은 Objective-C 프로그램에서 사용되는 클래스 및 객체와 관련된 정보를 저장합니다.

others: 위에 언급된 섹션 이외의 섹션들의 크기를 나타냅니다. 여기에는 BSS 섹션과 같은 초기화되지 않은 전역 변수가 포함될 수 있습니다.

dec: 섹션의 크기를 10진수로 나타낸 값입니다.

hex: 섹션의 크기를 16진수로 나타낸 값입니다.

## stream state

ios_base::
goodbit // good()
eofbit // eof()
failbit // fail()
badbit // bad()

## 입력 버리기

[clear](https://en.cppreference.com/w/cpp/io/basic_ios/clear)

```cpp
cin.clear(); // discard everything
cin.ignore();         // discard one char
cin.ignore(10);       // discard 10 char
cin.ignore(10, '\n'); // discard 10 char but stop when \n
cin.ignore(LLONG_MAX, '\n');
```

```cpp
int main(void) {
    int a;
    cin >> a;

    if (cin.fail()) {
        cout << "invalid input\n";
        cin.clear();
        cin.ignore(LLONG_MAX, '\n');

        // retry
        cin >> a;
        cout << a;
    }

    return 0;
}
```

## 한 줄 읽기

```cpp
char buffer[100];

// 9개의 문자 읽어옴. 마지막은 null char(\0)
// \n는 입력 스트림에 남아 있음.
// https://en.cppreference.com/w/cpp/io/basic_istream/get
cin.get(buffer, 10);
printf("%s\n", buffer);

// 9개의 문자 읽어옴. 마지막은 null char(\0)
// get과 달리 \n는 입력 스트림에 없음. 그래서 get'line'
// https://en.cppreference.com/w/cpp/io/basic_istream/getline
cin.getline(buffer, 10, '!'); // read until met '!'
printf("%s\n", buffer);
```
