#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("varf.in");
ofstream fout("varf.out");

int n, v[12], s[12], l, ok;

void afis() {
    int cr = 0, sc = 0;
    for (int i = 1; i < l; ++i) {
        if (s[i] < s[i + 1] && sc)
            cr = 1;
        else
            if()
    }
}

int valid(int k) {
    for (int i = 1; i < k; ++i)
        if (s[i] == s[k])
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = 1; i <= n; ++i) {
        s[k] = v[i];
        if (valid(k))
            if (k == l)
                afis();
            else
                bt(k + 1);
    }
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (l = 3; l < n; ++l)
        bt(1);
    if (ok == 0)
        fout << 0;
    return 0;
}
