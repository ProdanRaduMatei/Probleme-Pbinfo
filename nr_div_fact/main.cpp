#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

const int N = 1e5 + 1;
bool ciur[N];
int prime[N];
int k, dmax = 0;
typedef int NrMare[N];
unordered_map<int, int> f;
NrMare x;

void desc(int n)
{
    int i = 1;
    while (i <= k && prime[i] * prime[i] <= n)
    {
        while (n % prime[i] == 0)
        {
            n /= prime[i];
            f[prime[i]]++;
        }
        i++;
    }
    if (n > 1)
        f[n]++;
}

void inmultire(NrMare x, int val)
{
    int t = 0;
    for (int i = 1; i <= x[0]; ++i)
    {
        t += x[i] * val;
        x[i] = t % 10;
        t /= 10;
    }
    while (t)
    {
        x[++x[0]] = t % 10;
        t /= 10;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int d = 2; d * d <= n; ++d)
        if (ciur[d] == 0)
            for (int i = d * d; i <= n; i += d)
                ciur[i] = 1;
    k = 0;
    for (int i = 2; i <= n; ++i)
        if (ciur[i] == 0)
            prime[++k] = i;
    for (int i = 2; i <= n; ++i)
        desc(i);
    x[0] = x[1] = 1;
    for (auto y : f)
        inmultire(x, y.second + 1);
    for (int i = x[0]; i >= 1; i--)
        cout << x[i];
    return 0;
}