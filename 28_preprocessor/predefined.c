#include <stdio.h>

/*
    https://en.cppreference.com/w/c/preprocessor/replace#Predefined_macros
*/
int main() {
    printf("__FILE__ : %s\n", __FILE__);
    printf("__LINE__ : %d\n", __LINE__);
    printf("__DATE__ : %s\n", __DATE__);
    printf("__TIME__ : %s\n", __TIME__);
    printf("__STDC_VERSION__ : %d\n", __STDC_VERSION__);
    /*
        199409L (C95)
        199901L (C99)
        201112L (C11)
        201710L (C17)
        202311L (C23)
    */
    return 0;
}
