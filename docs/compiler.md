<!-- toc -->

-   [compiler](#compiler)
    -   [env settings](#env-settings)
    -   [compiler frontend, backend](#compiler-frontend-backend)
    -   [명령어 예 clang, lldb, leaks, valgrind](#명령어-예-clang-lldb-leaks-valgrind)
        -   [if want to use gcc rather than clang](#if-want-to-use-gcc-rather-than-clang)
        -   [컴파일 플래그와 링커 플래그의 구분](#컴파일-플래그와-링커-플래그의-구분)
        -   [표준 라이브러리 경로는 어딘가?](#표준-라이브러리-경로는-어딘가)
        -   [설치한 라이브러리의 경로 문제로 컴파일러와 IDE intellesense의 경로가 일치하지 않을 경우](#설치한-라이브러리의-경로-문제로-컴파일러와-ide-intellesense의-경로가-일치하지-않을-경우)
        -   [library를 pre-compiled binary로 사용하기 vs 내장 lib로 사용하기](#library를-pre-compiled-binary로-사용하기-vs-내장-lib로-사용하기)
        -   [clang](#clang)
        -   [clang++](#clang-1)

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

## 명령어 예 clang, lldb, leaks, valgrind

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
    -   `-I` : 컴파일러에게 헤더 파일을 찾을 추가적인 디렉토리를 지정합니다.

-   링커 플래그
    -   `-l`: 라이브러리 이름 (표준 라이브러리와 -L로 추가 제공된 경로에서 특정 라이브러리를 추가)
        -   pre-compiled된 binary를 연결함. SDL2, lua, ...
    -   `-L`: 링커에게 라이브러리 파일을 찾을 추가적인 디렉토리를 지정합니다. 라이브러리 경로 (표준 라이브러리 경로 외에 추가 경로 제공)
    -   `-o`: 출력 파일 이름

### 표준 라이브러리 경로는 어딘가?

```bash
clang -print-search-dirs
# programs: =/Library/Developer/CommandLineTools/usr/bin
# libraries: =/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0

echo $LIBRARY_PATH
or
echo $LD_LIBRARY_PATH

```

### 설치한 라이브러리의 경로 문제로 컴파일러와 IDE intellesense의 경로가 일치하지 않을 경우

심볼릭 링크와 실제 경로: Homebrew는 종종 실제 라이브러리 파일을 Cellar 디렉토리에 설치하고, /opt/homebrew/include나 /opt/homebrew/lib와 같은 일반적인 위치에는 심볼릭 링크를 생성합니다. sdl2-config 스크립트는 이러한 심볼릭 링크를 따라가서 헤더 파일과 라이브러리 파일의 위치를 제공합니다.

컴파일러는 sdl2-config 스크립트의 결과를 기반으로 SDL2 헤더 파일과 라이브러리를 찾습니다. 반면, IDE(Integrated Development Environment)는 프로젝트 설정에 명시된 경로를 따라 헤더 파일을 찾습니다. 이 두 설정이 불일치할 경우, 경로 문제가 발생할 수 있습니다.

가급적이면 c_cpp_properties.json에 Cellar가 아닌 /opt/homebrew/include, /opt/homebrew/lib를 직접 명시하고, 컴파일러에서도 이를 참조하도록 설정하는 것이 좋다.

includePath 한 끝에 의해 달라지므로 유의할 것.

```json
"includePath": [
    "${workspaceFolder}/**",
    "/opt/homebrew/include/**" // 이 경우 <SDL2/SDL.h>로 임포트
    "/opt/homebrew/include/SDL2" // 이 경우 <SDL.h>로 임포트
],
```

### library를 pre-compiled binary로 사용하기 vs 내장 lib로 사용하기

-   pre-compiled binary로 사용하기

    -   -l 옵션으로 링킹해주고, 바이너리를 -L로, 헤더 경로를 -I로 추가해주면 됨.
    -   이 방식의 장점은, 컴파일 타임을 잡아 먹지 않는다는 것.

-   내장 lib로 사용하기
    -   내장 lib로써 사용하고 있어 소스코드를 전부 다 담고 있다. -I 경로만 추가해주면 됨.
    -   이 방식의 장점은, 커스터마이징이 용이하고 플랫폼에 종속되지 않는다는 것. 물론 손이 좀 더 가긴 한다.

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
