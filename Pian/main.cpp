#include <bits/stdc++.h>

using namespace std;

ifstream fin("pian.in");
ofstream fout("pian.out");

struct {
    int nrclape, poz;
}clapa;

int main()
{
    int n, c, v[100001], x[100001], m = 0;
    fin >> c >> n;
    fin >> v[1];
    for (int i = 2; i <= n; ++i) {
        fin >> v[i];
        int e = cmmdc(v[i - 1], v[i]);
        if (e != 1) {
            if (v[i - 1] != e) {
                ++f[e];
                x[++m] = v[i - 1];
                v[i - 1] = e;
            }
            else if (v[i] != e) {
                ++f[e];
                x[++m] = v[i];
                v[i] = e;
            }
        }
    }
    if (c == 1) {
        int s = 0;
        for (int i = 1; i <= n; ++i)
            s = s + v[i];
        fout << s;
    }
    else {

    }
    return 0;
}
