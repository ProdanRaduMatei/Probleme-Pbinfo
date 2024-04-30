#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL

int n, x;
int dp[100005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        dp[x] = max(dp[x], dp[x - 1] + 1);
    }
    int maxi = 0;
    for (int i = 1; i <= n; ++i)
        maxi = max(maxi, dp[i]);
    cout << n - maxi;
    return 0;
}