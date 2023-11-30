#include <stdarg.h>
#include <stdio.h>

void printf_custom(const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    {
        while (*format != '\0') {
            switch (*format) {
            case 'c':
                printf("%c", va_arg(ap, int));
                break;
            case 'd':
                printf("%d", va_arg(ap, int));
                break;
            case 's':
                printf("%s", va_arg(ap, char*));
                break;
            default:
                printf("%c", *format);
                break;
            }
            format++;
        }
    }
    va_end(ap);
}

int main(void) {
    printf_custom("c\n", 'A');
    printf_custom("d\n", 3);
    printf_custom("s\n", "abcd");
    printf_custom("c d s\n", 'B', 5, "abcd");

    return 0;
}