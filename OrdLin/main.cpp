#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101][101];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        v[i][0] = 0;
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            v[i][0] = v[i][0] + v[i][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int l = i + 1; l <= n; ++l) {
            if (v[i][0] > v[l][0]) {
                for (int j = 0; j <= m; ++j) {
                    swap (v[i][j], v[l][j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
