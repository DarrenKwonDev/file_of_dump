# cpp test

## google test(gtest) references

-   [gtest](https://github.com/google/googletest)

-   [official user guide](https://google.github.io/googletest/)

-   [cmake module googletest](https://cmake.org/cmake/help/git-stage/module/GoogleTest.html)

### assert vs expect

assert
= fatal : test fail and stop
= 실패시 test case를 즉시 종료함.

expect
= non-fatal :test fail but continue
= 실패 하더라도 test case를 계속 실행

### unit test structure

-   AAA pattern

    -   arrange(set up)
    -   act
    -   assert

-   given when then pattern
    -   given
    -   when
    -   then
