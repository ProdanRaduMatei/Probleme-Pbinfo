#include <bits/stdc++.h>

using namespace std;

ifstream fin("odaoni.in");
ofstream fout("odaoni.out");

int n, cf[10], d, aux, nrdiv = 1;

int mul(int n) {
    while (n) {
        if (cf[n % 10] == 0)
            return 0;
        n = n / 10;
    }
    return 1;
}

int main()
{
    fin >> n;
    aux = n;
    while (aux) {
        ++cf[aux % 10];
        aux = aux / 10;
    }
    if (cf[1])
        ++nrdiv;
    for (d = 2; d * d <= n; ++d)
        if (n % d == 0) {
            if (mul(d))
                ++nrdiv;
            if (d * d != n)
                if (mul(n / d))
                    ++nrdiv;
        }
    fout << nrdiv;
    return 0;
}
