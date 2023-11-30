#include <stdio.h>

// #는 쌍따옴표로 감싸라는 의미.
#define STRINGIFY(s) #s

// ##는 문자열 concat. 일종의 interpolation.
#define PRINT_ID(job) printf("%d\n", job##_id)

#define PRINT_DOC_TYPE(type) DOC_##type
enum DOCUMENT_TYPE {
    DOC_PPT = 0,
    DOC_EXCEL = 1,
    DOC_PDF = 2,
    DOC_HWP = 3,
};

int main() {
    int num = 1;
    printf("%s\n", STRINGIFY(Hello World));            // "Hello World"
    printf("%s\n", STRINGIFY(12346));                  // 123456
    printf("%s\n", STRINGIFY(num));                    // "num"
    printf("%s\n", STRINGIFY(STRINGIFY(Hello World))); // "STRINGIFY(Hello World)"
    printf("%s\n", STRINGIFY(\n));                     // 줄바꿈 2번

    printf("--------------------\n");

    int quant_id = 1;
    int dev_id = 2;
    int manager_id = 3;
    PRINT_ID(quant);   // 1
    PRINT_ID(dev);     // 2
    PRINT_ID(manager); // 3

    printf("--------------------\n");

    printf("%d\n", PRINT_DOC_TYPE(PPT));
    printf("%d\n", PRINT_DOC_TYPE(EXCEL));
    printf("%d\n", PRINT_DOC_TYPE(PDF));
    printf("%d\n", PRINT_DOC_TYPE(HWP));

    return 0;
}
