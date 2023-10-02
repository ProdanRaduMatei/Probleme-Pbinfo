#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
using namespace std;

const int nMAX = 160e3;

int n, a, b;
int v[nMAX + 1];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    cin >> a >> b;
    sort(v + 1, v + n + 1);
    long long secv = 0;
    for (int i = 1; i <= n; ++i) {
        int st = lower_bound(v + i + 1, v + n + 1, a - v[i]) - v;
        int dr = upper_bound(v + i + 1, v + n + 1, b - v[i]) - 1 - v;
        secv += dr - st + 1;
    }
    cout << secv;
}