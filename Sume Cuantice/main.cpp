#include <bits/stdc++.h>
using namespace std;

const int nMAX = 1e3;
const int kMAX = 1e3;

int t, n, k;
int maxrest[kMAX + 1];

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        fill(maxrest + 1, maxrest + kMAX+1, 0);
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            maxrest[i % k + 1] = max(maxrest[i % k + 1], x);
        }
        cout << accumulate(maxrest + 1, maxrest + k + 1, 0LL) << '\n';
    }
    return 0;
}