#include <iostream>
#include <bitset>
#include <algorithm>

#define SIZE 500000

void ciurFunc(int arr[]) {
    std::bitset<SIZE> t;
    t[0] = 1;
    t[1] = 1;
    int i, k = 0;
    for (i = 2; i * i < SIZE; i++)
        if (t[i] == 0) {
            arr[k++] = i;
            for (int j = 2; j * i < SIZE; j++)
                t[i * j] = 1;
        }
    while (i < SIZE) {
        if (t[i] == 0)
            arr[k++] = i;
        i++;
    }
}

void fill_arr(int out[], int ciur[]) {
    int count = 0;
    for (int i = 0; i < 6000 && count < SIZE; i++)
        for (int j = i; j < 6000 && count < SIZE; j++) {
            out[count] = ciur[i] * ciur[j];
            count++;
        }
}

int main() {
    int ciur[SIZE / 2];
    ciurFunc(ciur);
    int out[SIZE] = {0};
    fill_arr(out, ciur);
    std::sort(out, out + SIZE);
    int in, i = 0;
    while (out[i] == 0)
        i++;
    std::cin >> in;
    std::cout << out[in + i - 1];
    return 0;
}