

<!-- toc -->

- [compiler](#compiler)
  * [env settings](#env-settings)
  * [compiler frontend, backend](#compiler-frontend-backend)
  * [명령어 예 clang, lldb, leaks, valgrind...](#%EB%AA%85%EB%A0%B9%EC%96%B4-%EC%98%88-clang-lldb-leaks-valgrind)
    + [if want to use gcc rather than clang](#if-want-to-use-gcc-rather-than-clang)
    + [컴파일 플래그와 링커 플래그의 구분](#%EC%BB%B4%ED%8C%8C%EC%9D%BC-%ED%94%8C%EB%9E%98%EA%B7%B8%EC%99%80-%EB%A7%81%EC%BB%A4-%ED%94%8C%EB%9E%98%EA%B7%B8%EC%9D%98-%EA%B5%AC%EB%B6%84)
    + [clang](#clang)
    + [clang++](#clang)
    + [lldb](#lldb)
    + [leaks](#leaks)
    + [기타 도구들](#%EA%B8%B0%ED%83%80-%EB%8F%84%EA%B5%AC%EB%93%A4)

<!-- tocstop -->

# compiler

## env settings

[EditUsing Clang in Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-clang-mac)  
[Visual Studio Code C++ July 2021 Update: Disassembly View, Macro Expansion and Windows ARM64 Debugging](https://devblogs.microsoft.com/cppblog/visual-studio-code-c-july-2021-update-disassembly-view-macro-expansion-and-windows-arm64-debugging/#disassembly-view)
[Debug C++ in Visual Studio Code](https://code.visualstudio.com/docs/cpp/cpp-debug)

## compiler frontend, backend

컴파일러는 frontend, backend로 나뉨.
프론트엔드는 소스 코드를 읽고 문법적으로 분석하며 중간 코드(Intermediate Code)를 생성합니다. 이 중간 코드는 프로그램의 의미를 나타내는 중간 표현입니다. 이어서 백엔드가 중간 코드를 가져와서 어셈블리 코드 또는 기계어로 번역하여 실행 파일을 생성합니다.

-   clang
    -   LLVM(Low-Level Virtual Machine) 백엔드를 사용하는 계열
    -   gcc 사용 인터페이스를 거의 비슷함. mac에서 gcc는 clang을 wrapping한 것일 정도.
    -   보통 이걸 쓰게 된다.
-   gcc (GNU Compiler Collection)
    -   거의 모든 표준 지원 + cross platform
    -   그래서 GCC의 각 아키텍처별 백엔드는 해당 아키텍처의 이름이라. (ARM 아키텍처, RISC-V 아키텍처, ...)
-   MS visual C++
    -   MASM(Microsoft Macro Assembler) 백엔드를 사용함.
    -   cpp 컴파일러임에도 .c 확장자면 컴파일함.
    -   C99 표준. C11은 거의 지원하지 않음.
    -   window에서는 이 컴파일러를 사용하는 경우가 많음.

## 명령어 예 clang, lldb, leaks, valgrind...

### if want to use gcc rather than clang

```bash
brew install gcc
# gcc-13 (or something)
gcc-13 -v
```

now use,

use `gcc-13` instead of `clang`
use `g++-13` instead of `clang++`

### 컴파일 플래그와 링커 플래그의 구분

-   컴파일 플래그

    -   `-Wall`: 일반적인 경고 메시지를 모두 활성화합니다.
    -   `-Wextra`: -Wall보다 더 많은 경고 메시지를 활성화합니다.
    -   `-Werror`: 모든 경고를 오류로 처리하여 경고가 발생하면 컴파일을 중단합니다.
    -   `-std=c++17`: C++17 표준을 사용합니다.
    -   `-O1`, `-O2`, `-O3`: 점진적으로 강화되는 최적화 수준을 제공합니다.
    -   `-D` : 매크로 정의 (-DDEBUG, -D_THREAD_SAFE)
    -   `-I` : 추가적으로 정의한 사용자 헤더 파일 경로

-   링커 플래그
    -   `-l`: 라이브러리 이름
    -   `-L`: 라이브러리 경로
    -   `-o`: 출력 파일 이름

```bash
sdl2-config --libs --cflags
-L/opt/homebrew/lib -lSDL2
-I/opt/homebrew/include/SDL2 -D_THREAD_SAFE

sdl2-config --libs
-L/opt/homebrew/lib -lSDL2
```

### clang

[clang docs](https://clang.llvm.org/docs/ClangCommandLineReference.html)  
[gcc docs](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html)

```bash
clang -std=c89 -W -Wall -pedantic-errors $file

clang -E $file # preprocessor output (translation unit)
clang -S $file # assembly output
clang -c $file # object output
clang -save-temps $file # 컴파일 과정 중에 생성되는 임시 파일들을 보존. 위 명령어들 귀찮아서 보통 다 저장할 때 사용함.

# for your convenience
nodemon --exec "clang $file && ./a.out" -e c

nodemon --exec "gcc-13 ./*.cpp && ./a.out < ./input" -e cpp
```

### clang++

```bash
# sd2 check
sdl2-config --version # 2.28.5
sdl2-config --libs
sdl2-config --libs --cflags # 컴파일러 플래그와 링커 플래그를 한번에 출력
brew info sdl2 # check include path

clang++ -Wall -std=c++17 Main.cpp $(sdl2-config --libs --cflags) -o Main
```

### lldb

https://lldb.llvm.org/use/tutorial.html

```bash
clang -g ./main.c
lldb ./a.out
b main.c:30 # 30번째 줄에 breakpoint 걸기
r # 진행
n # 한 줄 씩
```

### leaks

안 다뤄봄. 메모리 누수 탐지에 용이함.

### 기타 도구들

> 지금 와서 C 코드를 짜야 한다면 무조건 메모리 안전성을 확인해 주는 도구를 사용해야 한다. 이를테면 Zed Shaw의 《깐깐하게 배우는 C(Learn C the Hard Way)》에서는 초장에 바로 valgrind를 쓰도록 하고 있다.
>
> -   https://hut.mearie.org/c-language/

https://github.com/nothings/single_file_libs
