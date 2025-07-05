#ifdef EZ
#include "./ez/ez.h"
#else
#include <bits/stdc++.h>
#endif
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;

const int nMAX = 200;

int n, m;
int x[nMAX + 1];
int y[nMAX + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    for (int i = n; i >= 1; --i)
        if (x[i] % 2 == 1)
            y[++m] = x[i];
    for (int i = 1; i <= m; ++i)
        cout << y[i] << ' ';
    return 0;
}