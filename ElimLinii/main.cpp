#include <iostream>

using namespace std;

int prim(int x) {
    if (x <= 1)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int d = 3; d * d < x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int n, m, v[101][101];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> v[i][j];
    for (int i = 1; i <= n; ++i) {
        if (prim(v[i][1]) == 0) {
            for (int j = 1; j <= m; ++j) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
