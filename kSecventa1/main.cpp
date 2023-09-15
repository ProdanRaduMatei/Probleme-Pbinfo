#include <bits/stdc++.h>

using namespace std;

int a[1001], n, k;
int b, e, ok = 0;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n - k && !ok; ++i) {
        for (int j = i + 1; j <= n - k + 1 && !ok; ++j) {
            int ii = i, jj = j, nr = 0;
            while (a[ii] == a[jj] && nr < k) {
                ++ii;
                ++jj;
                ++nr;
            }
            if (nr == k) {
                ok = 1;
                b = i;
                e = jj - k;
            }
        }
    }
    if (ok)
        cout << b << " " << e;
    else
        cout << "NU";
}
