
/*
inline function.

MACRO 함수처럼 복사-붙여넣기 방식으로 함수 호출에 대한 오버헤드가 없어짐
이는 곧 컴파일 시점에 함수 구현을 알아야 하므로 헤더 파일에 구현까지 존재해야 함.
단 인라인이 되느냐 마느냐는 컴파일러별 차이 존재

inline function의 문제
"인라인이 실패할 경우를 대비하여 함수 심볼도 만들어야 함"
실제 존재하는 함수가 아닌 대체용 함수이므로 함수 symbol을 만들지 않음.
문제는, C의 특성상 인라인 함수를 정의하였으나 인라인 않은 경우가 존재하고, 함수 심볼이 없음에 따라 실제 함수 대체가 일어나지 않게 됨.
따라서 inline function을 위해서 아래와 같이 작성해야 함.

1. .h에 inline 함수 구현
2. 그에 대응하는 .c 파일 만듦
3. .c에서 .h을 include
4. .c에서 인라인 함수의 선언을 한 후 extern 처리
*/
#ifndef ADDER_H
#define ADDER_H

inline int adder(int a, int b) {
    return a + b;
};

#endif // !ADDER_H