#include <iostream>

using namespace std;

int main()
{
    int n, m, v[51][51], ok = 0, x, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> v[i][j];
    for (int j = 1; j <= m; ++j) {
        ok = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == 1)
                x = v[i][j];
            else if (i == n)
                if (ok == 0)
                    if (v[i][j] == x) {
                        cout << x << " ";
                        ++cnt;
                    }
            else if (i != n && i != 1)
                if (v[i][j] != x)
                    ok = 1;
        }
    }
    if (cnt == 0)
        cout << "nu exista";
    return 0;
}
