#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101][101], c[1000001] = {0}, M = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            if (i == 1 || j == 1 || i == n || j == m) {
                c[v[i][j]] = 1;
                if (v[i][j] > M)
                    M = v[i][j];
            }
        }
    }
    for (int i = 0; i <= M; ++i)
        if (c[i] == 1)
            cout << i << " ";
    return 0;
}
