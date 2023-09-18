// 이하 함수 선언 => {}가 없음. 즉, body가 없고 함수 선언만 함.
int sum(void); // 함수 선언. 매개 변수 없음
int sum(); // 함수 선언. 매개 변수가 존재하는데 아직 뭔지 모름


// 이하 함수 정의 => {}가 있음. 즉, body가 있음.
int sum(void) {} // 함수 정의. 매개 변수 없음
int sum() {} // 함수 정의. 매개 변수 없음
int sum(const int num1, const int num2) {} // 함수 정의. 매개 변수 두 개
