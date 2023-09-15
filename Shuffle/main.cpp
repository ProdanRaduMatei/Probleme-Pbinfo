#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

int n, v[9], f[3][9], s[9], ok;

void afis() {
    ok = 1;
    for (int i = 1; i <= n; ++i)
        fout << s[i] << " ";
    fout << endl;
}

int valid(int k) {
    if (f[1][s[k]] == s[k - 1] ||f[2][s[k]] == s[k - 1])
        return 0;
    for (int i = 1; i < k; ++i)
        if (s[k] == s[i])
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = 1; i <= n; ++i) {
        s[k] = v[i];
        if (k > 1 && valid(k)) {
            if (k == n)
                afis();
            else
                bt(k + 1);
        }
        else if (k == 1) {
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
    if (n > 1 && n < 4) {
        fout << "nu exista";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        f[1][v[i]] = v[i - 1];
        f[2][v[i]] = v[i + 1];
    }
    sort(v + 1, v + 1 + n);
    bt(1);
    if (ok == 0)
        fout << "nu exista";
    return 0;
}
