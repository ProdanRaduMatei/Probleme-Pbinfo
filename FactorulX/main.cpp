#include <bits/stdc++.h>

using namespace std;

ifstream fin("factorulx.in");
ofstream fout("factorulx.out");

int factorx(int n)
{
    long long P = 1;
    if (n % 2 == 0)
    {
        P *= 2;
        while (n % 2 == 0)
            n >>= 1;
    }
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
        {
            P *= i;
            while (n % i == 0)
                n /= i;
        }
    if (n > 2)
        P *= n;
    return P;
}

int n, v[1024], fact[524288];

int main()
{
    int i, j, m, k = 0, P;
    fin >> n;
    for (i = 1; i <= n; ++i)
        fin >> v[i];
    for (i = 1; i < n; ++i)
        for (j = i + 1; j <= n; ++j)
        {
            m = __gcd(v[i], v[j]);
            P = factorx(m);
            if (!binary_search(fact + 1, fact + k + 1, P))
            {
                fact[++k] = P;
                sort(fact + 1, fact + k + 1);
            }
        }
    fout << k << '\n';
    sort(fact + 1, fact + k + 1);
    for (i = 1; i <= k; ++i)
        fout << fact[i] << ' ';
    return 0;
}