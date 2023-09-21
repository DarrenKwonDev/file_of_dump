/*
    
    header에 extern을 선언함으로써 해당 header를 include하는 파일에서 외부 변수를 사용하게 된다.


    library 빌드를 위해선 extern을 header에 넣음.
    .c에 extern을 포함한다면 해당 파일 안에서만 외부 변수를 사용하려는 의도이다.
*/

extern int g_cnt;
void inc_cnt(void); // 함수는 extern 선언하지 않아도 됨.