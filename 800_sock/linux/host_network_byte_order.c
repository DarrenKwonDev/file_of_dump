#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void) {
    
    unsigned short hort_port = 0x1234;
    unsigned short net_port = htons(hort_port);
    unsigned long hort_addr = 0x12345678;
    unsigned long net_addr = htonl(hort_addr);

    // 현재 m1에선, litten endian CPU라서 반대로 출력됨.
    printf("%x\n", hort_port); // 1234
    printf("%x\n", net_port); // 3412

    printf("%lx\n", hort_addr); // 12345678
    printf("%lx\n", net_addr); // 78563412

    return 0;
}