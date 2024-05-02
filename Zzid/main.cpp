#include <bits/stdc++.h>

using namespace std;

ifstream fin("zzid.in");
ofstream fout("zzid.out");

map<int, int> v;

int main()
{
    int s = 0, a, b, n, m, maxim = 0, taietura;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        fin >> a;
        for (int j = 1; j <= a; ++j)
        {
            fin >> b;
            s += b;
            if (s == m)
                continue;
            v[s]++;
            if (v[s] > maxim)
            {
                maxim = v[s];
                taietura = s;
            }
            if (v[s] == maxim && abs(m - taietura - taietura) > abs(m - s - s))
                taietura = s;
        }
        s = 0;
    }
    fout << n - maxim << " " << abs(taietura - m + taietura);
    return 0;
}