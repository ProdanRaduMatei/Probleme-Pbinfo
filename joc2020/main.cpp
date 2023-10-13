#include <bits/stdc++.h>

#define NR 1000005

using namespace std;

ifstream fin("joc2020.in");
ofstream fout("joc2020.out");

int n, x, K, P[NR];
bitset <NR> viz;

void ciur() {
    for (int i = 2; i < NR; ++i)
        if (viz[i] == 0) {
            P[++K] = i;
            for (int j = i+i; j < NR; j += i)
                viz[j] = 1;
        }
}

int main() {
    ciur();
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> x;
        int nd = 1;
        for (int j = 1; j <= K && 1LL * P[j] * P[j] <= x; ++j) {
            if (x % P[j]) continue;
            int p = 0;
            while (x % P[j] == 0) {
                x /= P[j];
                ++p;
            }
            nd *= (p + 1);
        }
        if (x > 1)
            nd *= 2;
        fout << nd << " ";
    }
    return 0;
}