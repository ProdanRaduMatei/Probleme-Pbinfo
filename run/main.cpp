#include <bits/stdc++.h>
#define Nmax 100001

using namespace std;
unsigned long long int a[Nmax], Suf[Nmax], S[Nmax], G[Nmax];

int main()
{
    int n, m, k;
    ifstream f("run.in");
    f >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        f >> a[i];
    unsigned long long int SUM = 0, SUM1 = 0;
    for (int i = n; i >= 1; --i)
    {
        SUM += a[i];
        Suf[i] = SUM;
        SUM1 += (1ULL * n - 1ULL * i + 1) * a[i];
        S[i] = SUM1;
    }
    int s, d;
    for (int i = 0; i < m; ++i)
    {
        f >> s >> d;
        G[i] = S[s] - S[d + 1] - (1ULL * n - 1ULL * d) * (Suf[s] - Suf[d + 1]);
    }
    sort(G, G + m);
    unsigned long long int GO = 0;
    for (int i = 0; i < k; ++i)
        GO += G[i];
    ofstream g("run.out");
    g << GO << '\n';
    return 0;
}