<!-- toc -->

-   [lldb](#lldb)
    -   [문제 해결의 flow](#문제-해결의-flow)
-   [clangd](#clangd)
-   [valgrind](#valgrind)
-   [leaks](#leaks)
-   [기타 도구들](#기타-도구들)

<!-- tocstop -->

## lldb

<https://lldb.llvm.org/use/tutorial.html>

```bash
clang -g ./main.c
lldb ./a.out
b main.c:30 # 30번째 줄에 breakpoint 걸기
r # 진행
n # 한 줄 씩
```

-   프로그램 시작: 프로그램을 시작하려면, LLDB 셸에서 run 또는 r 명령어를 사용합니다.
-   브레이크포인트 설정: 특정 라인에 브레이크포인트를 설정하려면, breakpoint set --file [file.cpp] --line [line number] 명령어를 사용합니다.
-   함수에 브레이크포인트 설정: 특정 함수에 브레이크포인트를 설정하려면, b [function-name] 명령어를 사용합니다.
-   브레이크포인트 목록 확인: 설정된 브레이크포인트를 보려면, breakpoint list 명령어를 사용합니다.
-   계속 실행: 브레이크포인트에서 프로그램을 계속 실행하려면, continue 또는 c 명령어를 사용합니다.
-   단계별 실행: 현재 라인에서 다음 라인으로 이동하려면 step 또는 s 명령어를 사용합니다. 함수 내부로 들어가려면 step in 또는 si 명령어를 사용하고, 함수 밖으로 나가려면 step out 또는 so 명령어를 사용합니다.
-   변수 검사: 현재 스코프의 변수를 확인하려면 frame variable 또는 fr v 명령어를 사용합니다.
-   표현식 평가: 표현식을 평가하려면 expression 또는 expr 명령어를 사용합니다.
-   스택 트레이스 보기: 스택 트레이스를 보려면 bt 명령어를 사용합니다.

### 문제 해결의 flow

-   `b [function-name]` 나 `b [file]:[line]`로 의심되는 지점을 건다.
-   `r`로 실행한다.
-   다음과 같은 도구들을 이용해본다
    -   뭔가 터지면 `bt`로 스택 트레이스를 확인한다.
    -   문제가 되는 메모리 공간을 `memory read [주소]`로 확인한다.
    -   `expr [변수명] = [새로운 값]`으로 새로운 값으로 변경해본다
    -   `expr [변수명]` 혹은 `p [변수명]` 으로 변수를 확인해본다
    -   `frame variable [변수명]`, `fr v [변수명]`으로 현 프레임에서의 변수의 값을 확인한다.

아래의 내용을 보면 stack frame이 #0부터 차곡차곡 쌓인 것을 알 수 있다.
또한, gameengine`Registry::CreateEntity() 가 0x0000000100004f4c 에 존재하며, 문제가 해당 함수의 stack frame에서 28번째 줄에서 발생했음을 알 수 있다.

```bash
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x8)
  * frame #0: 0x0000000100004f4c gameengine`Registry::CreateEntity() + 28
    frame #1: 0x000000010000ae6c gameengine`Game::Setup() + 40
    frame #2: 0x000000010000ae08 gameengine`Game::RunGameLoop() + 28
    frame #3: 0x0000000100004618 gameengine`main + 56
    frame #4: 0x000000010011d08c dyld`start + 520
```

읽어보자면

```bash
# 시작 주소에서 28바이트를 읽어라.
memory read/x 0x0000000100004f4c --count 28
```

## [clangd](https://clangd.llvm.org/)

c/c++ default intellisense가 아주 느리다.  
clangd를 사용하자. c_cpp_properties.json과도 싸울 필요가 없어진다.

-   https://80000coding.oopy.io/6e809d3a-dea5-40f3-9c72-de454a9d3632

## [valgrind](https://valgrind.org/)

> 지금 와서 C 코드를 짜야 한다면 무조건 메모리 안전성을 확인해 주는 도구를 사용해야 한다. 이를테면 Zed Shaw의 《깐깐하게 배우는 C(Learn C the Hard Way)》에서는 초장에 바로 valgrind를 쓰도록 하고 있다.
>
> -   <https://hut.mearie.org/c-language/>

단순히 메모리 leak 뿐만 아니라 cache profiling 등 다양한 도구를 제공해준다. 다만 linux 환경에서만 제대로 동작하는 듯.

## leaks

안 다뤄봄. 메모리 누수 탐지에 용이함.

## 기타 도구들

<https://github.com/nothings/single_file_libs>
