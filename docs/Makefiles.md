<!-- toc -->

<!-- tocstop -->

CMake는 Makefiles를 생성하는 역할을 합니다. CMake 프로젝트를 설정하면 CMake는 해당 프로젝트에 대한 Makefiles를 생성하거나 다른 빌드 시스템 파일을 생성합니다.

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

# implicit rules

`make -p` to see all predefined variables

## etc

https://www.gnu.org/software/make/
https://makefiletutorial.com/
https://github.com/franneck94/UdemyMakefile/blob/master/.clang-format
