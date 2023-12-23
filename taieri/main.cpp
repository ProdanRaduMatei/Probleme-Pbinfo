#include <bits/stdc++.h>

using namespace std;

ifstream fin("taieri.in");
ofstream fout("taieri.out");

int n, m, a, b, c, d;
int v[100005];
long long S;
int l1, l2, l4, l8;

int main() {
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        l8 += v[i] / 8;
        v[i] = v[i] % 8;
        if (v[i]) {
            l4 += v[i] / 4;
            v[i] = v[i] % 4;
            if (v[i]) {
                l2 += v[i] / 2;
                v[i] = v[i] % 2;
            }
            if (v[i])
                l1 += v[i];
        }
    }
    fin >> m;
    for (int i = 1; i <= m; ++i) {
        fin >> a >> b >> c >> d;
        int daux = l8, caux = l4, baux = l2, aaux = l1;
        int ok = 1;
        if (d > daux)
            ok = 0;
        else {
            caux += (daux - d) * 2;
            if (c > caux)
                ok = 0;
            else {
                baux += (caux - c) * 2;
                if (b > baux)
                    ok = 0;
                else {
                    aaux += (baux - b) * 2;
                    if (a > aaux)
                        ok = 0;
                }
            }
        }
        fout << ok << " ";
    }
    return 0;
}