#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

// head <--> tail

void push(int x) {
    dat[tail] = x;
    tail++;
}

void pop() {
    head++;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail - 1];
}

void test() {
    push(10); // dat[0] = 10, tail = 1
    push(20); // dat[1] = 20, tail = 2
    push(30); // dat[2] = 30, tail = 3
    // [10, 20, 30]
    cout << front() << '\n'; // 10
    cout << back() << '\n';  // 30
    pop();                   // popped 10
    pop();                   // popped 20
    push(15);
    push(25);
    // 25 15 30
    cout << front() << '\n'; // 30
    cout << back() << '\n';  // 25
}

int main(void) {
    test();
}