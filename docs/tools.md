

<!-- toc -->

- [lldb](#lldb)
  * [문제 해결의 flow](#%EB%AC%B8%EC%A0%9C-%ED%95%B4%EA%B2%B0%EC%9D%98-flow)
- [leaks](#leaks)
- [기타 도구들](#%EA%B8%B0%ED%83%80-%EB%8F%84%EA%B5%AC%EB%93%A4)

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

-   `b [function-name]` 나 `breakpoint set --file [file.cpp] --line [line number]`로 의심되는 지점을 건다.
-   `r`로 실행한다.
-   뭔가 터지면 `bt`로 스택 트레이스를 확인한다.
-   문제가 되는 메모리 공간을 `memory read [주소]`로 확인한다.
-   `expr [변수명] = [새로운 값]`으로 새로운 값으로 변경해본다

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

## leaks

안 다뤄봄. 메모리 누수 탐지에 용이함.

## 기타 도구들

> 지금 와서 C 코드를 짜야 한다면 무조건 메모리 안전성을 확인해 주는 도구를 사용해야 한다. 이를테면 Zed Shaw의 《깐깐하게 배우는 C(Learn C the Hard Way)》에서는 초장에 바로 valgrind를 쓰도록 하고 있다.
>
> -   <https://hut.mearie.org/c-language/>

<https://github.com/nothings/single_file_libs>
