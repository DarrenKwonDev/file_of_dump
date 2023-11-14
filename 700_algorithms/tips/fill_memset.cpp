#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int arr[10][10];

    fill(&arr[0][0], &arr[0][0] + 10 * 10, 20);

    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    memset(arr, 0, sizeof(arr));
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}