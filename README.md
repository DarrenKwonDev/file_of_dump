# clang_tutorial

## 권고 사항

-   전방 선언 꼭 해라. 함수 선언은 필수라 생각해라.
    -   C89 기준 아직 등장하지 않은 함수는 int 반환 함수로 컴파일러가 알아서 가정하기 때문임
-   한 줄에서 함수 여러 번 호출 하지 말 것 (unspecified behavior)
-   한 줄에서 동일 변수를 여러 번 바꾸지 말 것 (undefined behavior)
-   조건문에서는 short circuit evaluation 유의
-   전역 변수 prefix `g_` 붙이기
-   가급적 모든 변수에 const를 붙이는게 좋다. (rust 기본 동작처럼)

## env settings

[EditUsing Clang in Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-clang-mac)

## clang command

[clang docs](https://clang.llvm.org/docs/ClangCommandLineReference.html)

```bash
clang -std=c89 -W -Wall -pedantic-errors $file
```

## simple assembly

cmp: compare  
je : jump if equal  
jz : jump if zero  
jg : jump if greater  
jl : jump if less  
xor : exclusive or  
pop : pop stack  
push: push stack  
call: call function  
ret : return from function  
mov : move  
dec : decrement  
inc : increment
