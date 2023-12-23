#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

ifstream fin("barliga.in");
ofstream fout("barliga.out");

int main() {
    int n, v;
    fin >> n >> v;
    vector<int> cfv(v + 1);
    for (int i = 0; i < n; ++i) {
        int nr;
        fin >> nr;
        for (int j = 0; j < nr; ++j) {
            int x;
            fin >> x;
            cfv[x] |= (1<<i);
        }
    }
    vector<int> nrv(1<<n);
    for (int i = 1; i <= v; ++i)
        ++nrv[cfv[i]];
    int mincnt = v + 1, mini = 0;
    for (int i = 0; i < (1<<n); ++i)
        if (nrv[i] < mincnt) {
            mincnt = nrv[i];
            mini = i;
        }
    fout << v - mincnt << endl << __builtin_popcount(mini) << " ";
    for (int i = 0; i < n; ++i)
        if (mini&(1<<i))
            fout << i + 1 << " ";
}