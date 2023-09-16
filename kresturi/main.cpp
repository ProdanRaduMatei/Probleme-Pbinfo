#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    cin >> n;
    for (int t = 0; t < n; ++t) {
        cin >> k;
        if (t % 2 == 0)
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < k; ++j)
                    cout << (i + j) % k << ' ';
                cout << '\n';
            }
        else
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < k; ++j)
                    cout << (i * j) % k << ' ';
                cout << '\n';
            }
    }
    return 0;
}