#include <stdio.h>
#include <string.h>

int compare_string(const void* a, const void* b) {
    const char** w0 = (const char**)a;
    const char** w1 = (const char**)b;

    return strcmp(*w0, *w1);
}

int compare_string_desc(const void* a, const void* b) {
    const char** w0 = (const char**)a;
    const char** w1 = (const char**)b;

    return strcmp(*w1, *w0);
}

enum { NUM_WORDS = 6 };

int main(void) {
    size_t i;
    const char* words[NUM_WORDS] = {
        "premium", "level", "cultured",
        "moaning", "skinny", "curve"};

    puts("\n== sort ascending ==");

    qsort(words, NUM_WORDS, sizeof(const char*), compare_string);
    for (i = 0; i < NUM_WORDS; ++i) {
        printf("%s\n", words[i]);
    }

    puts("\n== sort descending ==");

    qsort(words, NUM_WORDS, sizeof(const char*), compare_string_desc);
    for (i = 0; i < NUM_WORDS; ++i) {
        printf("%s\n", words[i]);
    }

    return 0;
}