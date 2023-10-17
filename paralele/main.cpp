#include <bits/stdc++.h>

#define N 100001

using namespace std;

ifstream fin("parale.in");
ofstream fout("parale.out");

int n, m, x, cnt;
bool v[2 * N];

int main() {
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= m; ++i) {
        fin >> x;
        for (j = 1; j * x <= 2 * n; ++j)
            v[j * x] = 1;
    }
    for (i = 1; i <= 2 * n; ++i)
        if (!v[i]) {
            if (i <= n)
                cnt += (i - 1);
            else
                cnt += (2 * n - i + 1);
        }
    fout << cnt;
    return 0;
}