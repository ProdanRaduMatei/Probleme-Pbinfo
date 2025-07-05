#include <iostream>

using namespace std;

int main()
{
    int n, m, v[1001][1001], cnt = 0, M = 10000;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m ; ++j)
            cin >> v[i][j];
    for (int j = 1; j <= m; ++j) {
        M = 10000;
        for (int i = 1; i <= n; ++i)
            if (v[i][j] < M)
                M = v[i][j];
        cnt = cnt + M;
    }
    cout << cnt;
    return 0;
}
