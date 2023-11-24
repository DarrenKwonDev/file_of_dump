

<!-- toc -->

- [docs](#docs)
- [compile process](#compile-process)
- [rules](#rules)
- [error handle](#error-handle)
- [etc](#etc)

<!-- tocstop -->

## docs

https://www.gnu.org/software/make/

## compile process

```bash
clang -std=c89 -W -Wall -pedantic-errors $file

clang -E $file # preprocessor output (translation unit)
clang -S $file # assembly output
clang -c $file # object output
clang -save-temps $file # 컴파일 과정 중에 생성되는 임시 파일들을 보존. 위 명령어들 귀찮아서 보통 다 저장할 때 사용함.
```

## rules

-   [implicit rules](https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html)

    -   CC: Program for compiling C programs; default cc
    -   CXX: Program for compiling C++ programs; default g-++
    -   CFLAGS: Extra flags to give to the C compiler
    -   CXXFLAGS: Extra flags to give to the C++ compiler
    -   CPPFLAGS: Extra flags to give to the C preprocessor
    -   LDFLAGS: Extra flags to give to compilers when they are supposed to invoke the linker

-   [pattern rules](https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html)

## error handle

Add -k when running make to continue running even in the face of errors. Helpful if you want to see all the errors of Make at once.
Add a - before a command to suppress the error
Add -i to make to have this happen for every command.

## etc

https://makefiletutorial.com/

-   I suggest that you always wrap it in the wildcard function $(wildcard \*.c) to avoid errors when no files are found.
-   `*` for searching filenames
-   `%` for pattern matching
