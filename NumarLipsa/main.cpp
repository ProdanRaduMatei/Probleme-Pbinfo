#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[10001], n, maxx = 0, f[10001] = {0}, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > maxx)
            maxx = a[i];
        ++f[a[i]];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= maxx; ++i) {
        ++cnt;
        if (f[i] == 0) {
            cout << i;
            break;
        }
    }
    if (cnt == maxx)
        cout << a[n - 1] + 1;
    return 0;
}
