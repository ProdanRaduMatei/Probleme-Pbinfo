#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101][101], cnt = 0;
    bool ok = 1;
    cin >> n >> m;
    for (int i= 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> v[i][j];
    for (int j = 1; j <= m; ++j) {
        int i = 1;
        ok = 1;
        while (i < n && ok == 1) {
            for (int k = i + 1; k <= n; ++k) {
                if (v[i][j] == v[k][j])
                    ok = 0;
            }
            ++i;
        }
        if (ok == 1)
            ++cnt;
    }
    cout << cnt;
    return 0;
}
