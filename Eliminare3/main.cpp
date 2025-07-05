#include <iostream>

using namespace std;

int main()
{
    int m, n, v[51][51];
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> v[i][j];
    for (int i = 1; i <= m; ++i)
        v[i][n - 1] = v[i][n];
    for (int j = 1; j <= n; ++j)
        v[m - 1][j] = v[m][j];
    --n;
    --m;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
