#include <bits/stdc++.h>

using namespace std;

const int nMAX = 100e3;

int n, q, v[nMAX + 2];
long long sp[nMAX + 2];

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        sp[i] = sp[i - 1] + v[i];
        if (v[i] == 0)
            v[i] = v[i - 1];
    }
    if (v[n] % 2 == 1)
    {
        v[n + 1] = v[n] + 1;
        sp[n + 1] = sp[n] + v[n + 1];
    }
    else
    {
        v[n + 1] = v[n];
        sp[n + 1] = sp[n];
    }
    auto getAns = [&](int dr) -> long long
    {
        if (dr == 0)
            return 0;
        return sp[n + 1] * (dr / (n + 1)) + 1LL * v[n + 1] * v[n + 1] * ((dr / (n + 1) - 1LL) * (dr / (n + 1)) / 2) + ((dr % (n + 1) == 0) ? (0) : (sp[dr % (n + 1)] + 1LL * v[dr % (n + 1)] * v[n + 1] * (dr / (n + 1))));
    };
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << getAns(r) - getAns(l - 1) << '\n';
    }
    return 0;
}