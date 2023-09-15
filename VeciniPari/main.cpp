#include <iostream>

using namespace std;

int main()
{
    int n, m, v[102][102], cnt = 0;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; ++i) {
        v[i][0] = 2;
        v[i][m + 1] = 2;
    }
    for (int j = 0; j <= m + 1; ++ j) {
        v[0][j] = 2;
        v[n + 1][j] = 2;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> v[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i + 1][j] % 2 == 0 && v[i - 1][j] % 2 == 0 && v[i][j - 1] % 2 == 0 && v[i][j + 1] % 2 == 0)
                ++cnt;
    cout << cnt;
    return 0;
}
