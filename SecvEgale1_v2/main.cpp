#include <bits/stdc++.h>

using namespace std;

int n, fr1[1000001], nr;
int lmax, r1, r2, l;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nr;
        if (!fr1[nr])
            fr1[nr] = i;
        else {
            l = i - fr1[nr] + 1;
            if (l > lmax) {
                lmax = l;
                r1 = fr1[nr];
                r2 = i;
            }
        }
    }
    cout << r1 << " " << r2;
    return 0;
}