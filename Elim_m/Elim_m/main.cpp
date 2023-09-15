#include <iostream>

using namespace std;

int main() {
    int n, v[20] = {0};
    char m[20];
    cin >> m >> n;
    for (int i = 1; i < strlen(m); ++i)
        ++v[m[i]];
    int i = 1, j = 9;
    while (i <= strlen(m) - n) {
        while (v[j] > 0) {
            cout << j;
            ++i;
            --v[j];
        }
        --j;
    }
    return 0;
}
