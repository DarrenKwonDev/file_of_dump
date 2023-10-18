#include <stddef.h>

#define QUEUE_SIZE (5)

int s_nums[QUEUE_SIZE];
size_t s_front = 0;
size_t s_back = 0;
size_t s_num_count = 0;

void enqueue(int n);
int dequeue(void);

int main(void) {
    // s_front s_back
    enqueue(3); //
    enqueue(33);
    enqueue(94);
    dequeue();
    enqueue(10);
    dequeue();
    dequeue();
    enqueue(27);
    enqueue(54);
    enqueue(27);

    return 0;
}

void enqueue(int n) {
    s_nums[s_back] = n;

    s_back = (s_back + 1) % QUEUE_SIZE;

    ++s_num_count;
}

int dequeue() {
    int ret;

    ret = s_nums[s_front];

    --s_num_count;
    s_front = (s_front + 1) % QUEUE_SIZE;

    return ret;
}