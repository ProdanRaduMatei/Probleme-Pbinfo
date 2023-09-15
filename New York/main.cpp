#include <bits/stdc++.h>

using namespace std;

ifstream fin("nyk.in");
ofstream fout("nyk.out");

int prim(int x) {
    if (x < 2)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int main()
{
    int n, m, a, b, cmax = 1, d, e, str, cldr = 0, h = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> m;
        fin >> a;
        d = 0;
        if (prim(a) && a >= d) {
            d = a;
            e = 1;
        }
        for (int j = 2; j <= m; ++j) {
            fin >> b;
            if (prim(b) && b >= d) {
                d = b;
                e = j;
            }
            a = __gcd(a, b);
        }
        if (a >= cmax) {
            cmax = a;
            str = i;
            cldr = e;
            h = d;
        }
    }
    fout << str << " " << cldr << endl << h;
    return 0;
}
