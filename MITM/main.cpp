#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second

using namespace std;

const int nMAX = 40;
int n, s;
int v[nMAX + 1];
vector<int> dp[nMAX + 1];


int main()
{
    cin.tie(0)->sync_with_stdio(0);cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n/2; ++i)
    {
        for (int j = 1; j < i; ++j)
            for (int x : dp[j])
                dp[i].pb(x + v[i]);
        dp[i].pb(v[i]);
    }
    dp[n/2].pb(0);
    for (int i = n/2+1; i <= n; ++i)
    {
        for (int j = n/2+1; j < i; ++j)
            for (int x : dp[j])
            {
                dp[i].pb(x + v[i]);
                dp[n].pb(x + v[i]);
            }
        dp[i].pb(v[i]);
        dp[n].pb(v[i]);
    }
    dp[n].pb(0);
    sort(dp[n].begin(), dp[n].end());
    int ansmax = 0;
    for (int i = 1; i <= n/2; ++i)
        for (int x : dp[i])
        {
            auto it = upper_bound(dp[n].begin(), dp[n].end(), s - x);
            if (it == dp[n].begin())
                continue;
            it--;
            ansmax = max(ansmax, x + *it);
        }
    cout << ansmax;
}