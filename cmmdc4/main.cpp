#include <iostream>

#define ll unsigned long long
#define MOD 1000000007

using namespace std;

int n, e[1000001];
ll s = 0;

void ciur()
{
    for (int i = 1; i <= n; ++i)
        e[i] = i;
    for (int i = 2; i <= n; ++i)
        if (e[i] == i)
            for (int j = i; j <= n; j += i)
                e[j] = e[j] / i * (i - 1);
}

void solve()
{
    ll temp = 0, p = 0;
    for (ll c = 1; c <= n; ++c)
    {
        p = ((c % MOD) * (c % MOD) * (c % MOD)) % MOD;
        for (ll k = 2; k * c <= n; ++k)
        {
            temp = k * e[k] / 2;
            temp--;
            s = ((s % MOD) + (p * temp * k * 2LL % MOD)) % MOD;
        }
    }
    cout << s;
}

int main()
{
    cin >> n;
    ciur();
    solve();
    return 0;
}