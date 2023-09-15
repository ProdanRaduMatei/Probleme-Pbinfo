#include <iostream>

using namespace std;

int main() {
    int n, v[16][16];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        v[i][1] = i + 1;
        v[i][n] = i + n;
        v[1][i] = i + 1;
        v[n][i] = i + n;
    }
    for (int j = n - 1; j > 1; --j)
        for (int i = 2; i < n; ++i)
            v[i][j] = v[i - 1][j + 1] + v[i][j + 1] + v[i + 1][j + 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}
