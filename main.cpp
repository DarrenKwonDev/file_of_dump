#include <iostream>
#include <sstream>

using namespace std;

/*
    동적인 길이를 가진 string이라면
    특정 길이보다 넘어간다면 malloc 새로 해줘야할텐데
    heap에 데이터 할당하는 작업이 overhead로 들어갈 수밖에 없음.
    애초에 stack에 정적으로 문자 배열 100개 깔아 놓고 시작하는 것에 비해 느려짐.
    길이가 가변되는 동적 문자열의 string + string은 느릴 수 밖에 없다.
    또한, 내부 버퍼 증가는 멀티 스레드 환경에서 안전하지 않을 수도 있다.

    그 결과,
    아직도 정해진 길이의 문자 배열 선언한 다음에 sprintf로 쓰는 작업을 C++에서도 자주함.
*/
int main(void) {

    string str = "pepe";

    return 0;
}