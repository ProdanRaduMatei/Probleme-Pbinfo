#include <iostream>
#include <cmath>
using namespace std;

int m[511][511];

void pat(int n, int L, int l, int c) {
    L /= 2;
    m[l][c] = n;
    if (n > 1) {
        int semiLatura = L / 2 + 1;
        pat(n - 1, L, l - semiLatura, c - semiLatura);
        pat(n - 1, L, l - semiLatura, c + semiLatura);
        pat(n - 1, L, l + semiLatura, c - semiLatura);
        pat(n - 1, L, l + semiLatura, c + semiLatura);
    }
}

int main() {
    int n;
    cin >> n;
    int L = pow(2, n) - 1;
    pat(n, L, L / 2, L / 2);
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < L; j++)
            cout << m[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
