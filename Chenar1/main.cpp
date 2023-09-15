#include <iostream>

using namespace std;

int main()
{
    int n, m, v[51][51], u;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            u = v[i][j];
        }
    for (int j = 1; j <= m; ++j) {
        v[1][j] = u;
        v[n][j] = u;
    }
    for (int i = 1; i <= n; ++i) {
        v[i][1] = u;
        v[i][m] = u;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
