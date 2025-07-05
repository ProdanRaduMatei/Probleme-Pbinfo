#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cerc.in");
ofstream fout("cerc.out");

int n, v[11], s[11], S, Sm, sm[11];

void afis() {
    S = 0;
    for (int i = 1; i < n; ++i)
        S = S + s[i] * s[i + 1];
    S = s[1] * s[n];
    if (S > Sm)
        for (int i = 1; i <= n; ++i)
            sm[i] = s[i];
}

int valid(int k) {
    for (int i = 1; i < k; ++i)
        if (s[k] == s[i])
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = 1; i <= n; ++i) {
        s[k] = v[i];
        if (valid(k)) {
            if (k == n)
                afis();
            else
                bt(k + 1);
        }
    }
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    sort(v + 1, v + 1 + n);
    bt(1);
    for (int i = 1; i <= n; ++i)
        fout << sm[i] << " ";
    return 0;
}
