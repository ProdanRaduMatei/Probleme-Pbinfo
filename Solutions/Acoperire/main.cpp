#include <iostream>

using namespace std;

int main()
{
    int n, m, k, l, c, p, v[1001][1001] = {0}, cn = 0;
    cin >> n >> m >> k;
    for (int a = 1; a <= k; ++a) {
        cin >> l >> c >> p;
        int i, j, z;
        i = l;
        j = c;
        z = 1;
        while (z <= p && j >= 1 && i >= 1) {
            v[i][j] = 1;
            --j;
            --i;
            ++z;
        }
        z = 1;
        i = l;
        j = c;
        while (z <= p && j <= m && i >= 1) {
            v[i][j] = 1;
            ++j;
            --i;
            ++z;
        }
        z = 1;
        i = l;
        j = c;
        while (z <= p && j >= 1 && i <= n) {
            v[i][j] = 1;
            --j;
            ++i;
            ++z;
        }
        z = 1;
        i = l;
        j = c;
        while (z <= p && j <= m && i <= n) {
            v[i][j] = 1;
            ++j;
            ++i;
            ++z;
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i][j] == 0)
                ++cn;
    cout << cn;
    return 0;
}
