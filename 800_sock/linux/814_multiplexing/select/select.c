
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>


#define BUFF_SIZE (30)

int main(int argc, char* argv[]) {
    fd_set read_set;
    char buff[BUFF_SIZE];

    FD_ZERO(&read_set); // 모든 비트를 0으로 초기화
    FD_SET(0, &read_set); // 0번 fd는 stdin을 의미. stdin을 관찰.
    

    struct timeval timeout;

    // select 호출 후 변화가 생긴 fd를 제외한 fd_set은 0으로 초기화됨.
    // 따라서 본래 관심 있던 fds들을 보존하기 위해 복사해야 함.
    fd_set cpy_read_set; 
    while (1) {
        cpy_read_set = read_set;

        // timeval 겍체 선언에 주의.
        // select 함수 호출 후 구조체의 멤버 값이 타임아웃이 발생하기 전까지 남았던 시간으로 바뀌게 됨.
        // 따라서 iterative 기반 select 서버에선 select할 때마다 새로 timeout을 설정해주어야 함.
        // 아래는 5.0초를 의미.
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        // fd의 갯수. 여기서는 표준입력만 존재하므로 1
        int result = select(1, &cpy_read_set, 0, 0, &timeout);
        // select 함수가 반환됨으로써 반응이 존재하는 fd만 cpy_read_set에 담기게 된다.
        
        if (result == -1) {
            printf("error when select\n");
            break;
        } else if (result == 0) {
            printf("timeout!\n");
            break;
        } else {
            if (FD_ISSET(0, &cpy_read_set)) {
                int read_sz = read(0, buff, BUFF_SIZE);
                buff[read_sz] = '\0';
                printf("msg from console : %s\n", buff);
            }
        }
    }

    return 0;
}