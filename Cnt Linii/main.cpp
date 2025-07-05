#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101][101], cnt = 0, x;
    bool ok = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            if (j == 1) {
                x = v[i][j];
                if (ok == 1)
                    ++cnt;
                ok = 1;
            }
            else
                if (v[i][j] != x)
                    ok = 0;
        }
    }
    cout << cnt;
    return 0;
}
