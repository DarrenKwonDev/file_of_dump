# cpp test

## google test(gtest) references

-   [gtest](https://github.com/google/googletest)

-   [official user guide](https://google.github.io/googletest/)

-   [cmake module googletest](https://cmake.org/cmake/help/git-stage/module/GoogleTest.html)

### assert vs expect

assert
= fatal : test fail and stop
= 실패시 test case를 즉시 종료함. 해당 test case의 이하 코드가 실행되지 않음.

expect
= non-fatal :test fail but continue
= 실패 하더라도 test case를 계속 실행. 해당 test case의 이하 코드가 실행됨.

### unit test structure

-   AAA pattern

    -   arrange(set up)
    -   act
    -   assert

-   given when then pattern
    -   given
    -   when
    -   then

### test flow

1. setUp : 테스트 메서드가 실행되기 전에 실행. 보통 테스트 메서드에서 사용할 객체를 생성하거나 초기화하는 용도로 사용.
2. tearDown : 개별 테스트 메서드가 실행된 후에 실행. 보통 setUp에서 할당한 리소스를 해제하는 용도로 사용.
3. setUpTestCase : 테스트 클래스 내의 모든 테스트 메서드가 실행되기 전에 한 번만 실행. 보통 테스트 클래스에서 사용할 객체를 생성하거나 초기화하는 용도로 사용.
4. tearDownTestCase : 테스트 클래스 내의 모든 테스트 메서드가 실행된 후에 한 번만 실행. 보통 setUpTestCase에서 할당한 리소스를 해제하는 용도로 사용.
