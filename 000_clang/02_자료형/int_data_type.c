#include <stdio.h>
#include <limits.h>

int main(void) {
    /*
        char
        1 byte
        ASCII(0~127) 표현하기에 충분. 

        만약 숫자형으로 사용하려면 unsigned, signed를 명시할 것.
        signed -> [0]000 0000 -> 2^7 = 128 -> -127 ~ 127
        unsigned(부호 없음) -> 0000 0000 -> 2^8 = 256 -> 0 ~ 255
    */
    unsigned char a = 96; // 96 means `a`
    a = a + 1; // b
    char char_size = CHAR_BIT;
    printf("char \n");
    printf("%c, %d, %d\n", a, a, char_size);

    /*
        short
        2 byte
        
        signed -> [0]000 0000 0000 0000 -> 2^15 = 32768 -> -32767 ~ 32767
        unsigned -> 0000 0000 0000 0000 -> 2^16 = 65536 -> 0 ~ 65535
    */
    short sh = 32767; // 2^15 - 1
    printf("short \n");
    printf("%d\n", sh);

    /*
        int
        4 byte

        signed -> [0]000 0000 0000 0000 0000 0000 0000 0000 -> 2^31 = 2147483648 -> -2147483647 ~ 2147483647
        unsigned -> 0000 0000 0000 0000 0000 0000 0000 0000 -> 2^32 = 4294967296 -> 0 ~ 4294967295
    */
    int i = INT_MAX; // 2^31 - 1
    unsigned i_2 = 100u; // unsigned literal
    int int_size = sizeof(int);
    
    printf("int \n");
    printf("%d, %d, %d\n", i, i_2, int_size);

    /*
        long
        8 byte
    */
    unsigned long l =  13532ul; // unsigned long literal
    long l_2 = 13532L; // long literal
    int lg_size = sizeof(long);

    printf("long \n");
    printf("%lu, %ld, %d\n", l, l_2, lg_size);


    return 0;
};