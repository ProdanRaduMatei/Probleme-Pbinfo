#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a[102][102];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m - 1; ++j)
            swap(a[i][j], a[i][j + 1]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
