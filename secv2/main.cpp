#include<bits/stdc++.h>

using namespace std;

ifstream fin("secv2.in");
ofstream fout("secv2.out");

const int VMAX=1000000;
int N, v[200005], l, k, lmax, poz, nr, Left, Right;
bool sieve[VMAX];

int main() {
    sieve[0] = sieve[1] = true;
    for (int j = 4;j <= VMAX; j += 2)
        sieve[j] = true;
    for (int i = 3; i * i <= VMAX; i += 2)
        if (!sieve[i])
            for (int j = i * i; j <= VMAX; j += 2 * i)
                sieve[j] = true;
    fin >> N >> k;
    for (int i = 1; i <= N; ++i) {
        fin >> nr;
        if (sieve[nr])
            v[i] = 1;
    }
    int cnt = 0;
    Left = 1;
    Right = 1;
    while (Right <= N) {
        cnt += v[Right];
        while (Left < Right && cnt > k) {
            cnt -= v[Left];
            ++Left;
        }
        if (Right - Left + 1 > lmax) {
            lmax = Right - Left + 1;
            poz = Left;
        }
        ++Right;
    }
    fout << lmax << ' ' << poz << '\n';
    return 0;
}