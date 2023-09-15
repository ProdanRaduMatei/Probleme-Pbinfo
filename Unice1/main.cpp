#include <bits/stdc++.h>

using namespace std;

ifstream fin("unice1.in");
ofstream fout("unice1.out");

int main()
{
    long long n, v[1001], f[1001], m = 1, c = 0;
    fin >> n >> v[1];
    f[m] =  v[1];
    for (int i = 2; i <= n; ++i) {
        int ok = 0;
        fin >> v[i];
        for (int j = 1; j <= m; ++j)
            if (f[j] == v[i])
                ok = 1;
        if (ok == 0)
            f[++m] = v[i];
    }
    for (int j = 1; j <= m; ++j) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (v[i] == f[j])
                ++cnt;
        if (cnt == 1)
            ++c;
    }
    fout << c;
    return 0;
}
