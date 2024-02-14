#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

ifstream fin("nrreg.in");
ofstream fout("nrreg.out");

ull x, y, z, a = 2, b = 3, c = 5, ultim = 1;

ull mini(ull x, ull y, ull z) {
    ull m = x;
    if (y < m)
        m = y;
    if (z < m)
        m = z;
    return m;
}

ull minim(ull n) {
    ull k = 0, rez = 1;
    while (n % 2 == 0) {
        ++k;
        n /= 2;
    }
    if (k % 2 != 0)
        rez *= 2;
    for (ull i = 3; i * i <= n; i += 2) {
        k = 0;
        while (n % i == 0) {
            ++k;
            n /= i;
        }
        if (k % 2 != 0)
            rez *= i;
    }
    if (n > 2)
        rez *= n;
    return rez;
}

int main() {
    int n;
    fin >> n;
    ull reg[n];
    reg[0] = 1;
    for (int i = 1; i < n; ++i) {
        ultim = mini(a, b, c);
        reg[i] = ultim;
        if (ultim == a) {
            ++x;
            a = reg[x] * 2;
        }
        if (ultim == b) {
            ++y;
            b = reg[y] * 3;
        }
        if (ultim == c) {
            ++z;
            c = reg[z] * 5;
        }
    }
    ull y = minim(ultim);
    fout << ultim << " " << y << " " << ultim / y;
    return 0;
}