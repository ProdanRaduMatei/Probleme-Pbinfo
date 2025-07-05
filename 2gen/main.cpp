#include <bits/stdc++.h>

using namespace std;

ifstream fin("2gen.in");
ofstream fout("2gen.out");

int n, m, v[7];

int OK(int k) {
    int c = 0;
    for (int i = 1; i < k; ++i)
        if (v[i] == v[k])
            ++c;
    if (c < 2)
        return 1;
    else
        return 0;
}

void Afisare(int k) {
    for (int i = 1; i <= m; ++i)
        fout << v[i] << " ";
    fout << endl;
}

void bck(int k) {
    for (int i = 1; i <= n; ++i) {
        v[k] = i;
        if (OK(k))
            if (k == m)
                Afisare(k);
            else
                bck(k + 1);
    }
}

int main()
{
    fin >> n >> m;
    bck(1);
    return 0;
}
