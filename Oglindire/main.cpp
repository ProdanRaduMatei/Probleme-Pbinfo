#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101][101];
    bool ok = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> v[i][j];
    for (int i = 1; i <= n; ++i) {
        ok = 1;
        if (v[i][1] % 2 == 0 && v[i][1] != 2)
            ok = 0;
        if (v[i][1] == 1 && v[i][1] == 0)
            ok = 0;
        for (int d = 3; d * d <= v[i][1]; d = d + 2)
            if (v[i][1] % d == 0)
                ok = 0;
        if (ok == 1)
            for (int j = 1; j <= m / 2; ++j)
                swap (v[i][j], v[i][m - j + 1]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
