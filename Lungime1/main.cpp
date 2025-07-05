#include <bits/stdc++.h>

using namespace std;

ifstream fin("lungime1.in");
ofstream fout("lungime1.out");

int v[100001], f[100001];

int main()
{
    int n, ind = 1, m = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        fin >> x;
        if (f[x] == 1) {
            if (ind - v[x] > m)
                m = ind - v[x];
        }
        else {
            ++f[x];
            v[x] = ind;
        }
        ++ind;
    }
    fout << m + 1;
    return 0;
}
