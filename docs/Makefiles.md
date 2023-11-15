<!-- toc -->

<!-- tocstop -->

## docs

https://www.gnu.org/software/make/

-   [implicit rules](https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html)
-   [pattern rules](https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html)

## compile process

```bash
clang -std=c89 -W -Wall -pedantic-errors $file

clang -E $file # preprocessor output (translation unit)
clang -S $file # assembly output
clang -c $file # object output
clang -save-temps $file # 컴파일 과정 중에 생성되는 임시 파일들을 보존. 위 명령어들 귀찮아서 보통 다 저장할 때 사용함.
```

## etc

https://www.gnu.org/software/make/
https://makefiletutorial.com/
https://github.com/franneck94/UdemyMakefile/blob/master/.clang-format
