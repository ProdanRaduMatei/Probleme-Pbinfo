#include <iostream>
#include <string.h>

using namespace std;

int stack[100];

void push(int x, int& dim) {
    stack[dim] = x;
    ++dim;
}

void pop(int& dim) {
    --dim;
    cout << stack[dim] << " ";
}

int main() {
    char s[256];
    cin >> s;
    int ctr = 0, l = strlen(s), dim = 0;
    for (int i = 0; i < l; ++i) {
        if (s[i] == '(') {
            ctr++;
            push(ctr, dim);
        }
        else
            pop(dim);
    }
    return 0;
}
