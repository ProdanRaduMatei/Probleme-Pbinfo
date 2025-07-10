#include <bits/stdc++.h>

using namespace std;

int n, x, cif;
unsigned long long cnt;
unordered_map<int, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        cif = 0;
        if (x < 10)
            ++m[1];
        else {
            while (x) {
                ++cif;
                x /= 10;
            }
            ++m[cif];
        }
    }
    for (auto it = m.begin(); it != m.end(); ++it)
        if (it->second) {
            cif = (it->second);
            cnt += 1ULL * cif * (cif - 1) / 2;
        }
    cout << cnt;
    return 0;
}