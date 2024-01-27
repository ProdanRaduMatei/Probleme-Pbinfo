#include <bits/stdc++.h>

using namespace std;

ifstream fin("nyk.in");
ofstream fout("nyk.out");

struct oras
{
    int lo, v[1005];
};
oras str[1005];
int n, gcd, gcdmax, nrcasa, casamax, nrgcdm;

int gcd_all(int a, int b)
{
    if (a == 0)
        return b;
    return gcd_all(b % a, a);
}

int prime(int nr)
{
    if (nr == 2)
        return 1;
    if (nr < 2)
        return 0;
    if (nr % 2 == 0)
        return 0;
    for (int d = 3; d * d <= nr; ++d)
        if (nr % d == 0)
            return 0;
    return 1;
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> str[i].lo >> str[i].v[1];
        gcd = str[i].v[1];
        for (int j = 2; j <= str[i].lo; ++j)
        {
            fin >> str[i].v[j];
            gcd = gcd_all(gcd, str[i].v[j]);
        }
        if (gcd >= gcdmax)
        {
            gcdmax = gcd;
            nrgcdm = i;
        }
    }
    for (int i = 1; i <= str[nrgcdm].lo; ++i)
        if (prime(str[nrgcdm].v[i]))
            if (str[nrgcdm].v[i] >= casamax)
            {
                casamax = str[nrgcdm].v[i];
                nrcasa = i;
            }
    if (nrcasa)
        fout << nrgcdm << " " << nrcasa << '\n' << casamax;
    else
        fout << "Nu am gasit casa!";
    return 0;
}