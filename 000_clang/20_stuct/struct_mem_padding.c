#include <stdio.h>

/*
    mem padding 이유?
    메모리를 읽어올 때 각 시스템의 워드(word) 경계에서 읽어오는 것이 효율적이기 때문에
*/

enum {
    NAME_LEN = 32,
};

typedef struct name {
    char lastname[NAME_LEN];
    char firstname[NAME_LEN];
} name_t;

// #pragma pack(push, 1) // 1바이트 단위로 정렬
typedef struct user_info {
    unsigned int id;       // 4
    name_t name;           // 64
    unsigned short height; // 2 -> memory padding + 2될 예정
    float weight;          // 4
    unsigned short age;    // 2 -> memory padding + 2될 예정
} user_info_t;             // 76 이지만 80으로 맞춰짐.
// #pragma pack(pop)

int main() {
    FILE* stream;
    user_info_t user;
    user_info_t user2;

    printf("size of struct: %zu\n", sizeof(user_info_t));

    user.id = 1;
    user.name = (name_t){"Lulu", "Lee"};
    user.height = 170;
    user.weight = 60.5;
    user.age = 20;

    stream = fopen("user_info.txt", "wb");
    if (stream == NULL) {
        perror("fopen");
        return 1;
    }

    int num_of_write = fwrite(&user, sizeof(user_info_t), 1, stream);
    printf("num_of_write: %d\n", num_of_write);
    fflush(stream);

    // re-open and read
    stream = fopen("user_info.txt", "rb");
    size_t num_of_success = fread(&user2, sizeof(user_info_t), 1, stream);
    printf("num_of_success: %zu\n", num_of_success);
    if (num_of_success == 1) {
        printf("id: %d\n", user2.id);
        printf("name: %s %s\n", user2.name.firstname, user2.name.lastname);
        printf("height: %d\n", user2.height);
        printf("weight: %f\n", user2.weight);
        printf("age: %d\n", user2.age);
    }

    if (fclose(stream) != 0) {
        // fclose는 성공시 0 실패시 EOF를 반환한다.
        fprintf(stderr, "Failed to close file.\n");
    }

    return 0;
}
