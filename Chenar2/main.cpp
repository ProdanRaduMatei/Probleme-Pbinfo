#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101][101], x;
    bool ok = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> v[i][j];
    cin >> x;
    for (int j = 1; j <= m; ++j)
        if (v[1][j] == x || v[n][j] == x) {
            cout << "DA";
            return 0;
        }
    for (int i = 1; i <= n; ++i)
        if (v[i][1] == x || v[i][m] == x) {
            cout << "DA";
            return 0;
        }
    cout << "NU";
    return 0;
}
