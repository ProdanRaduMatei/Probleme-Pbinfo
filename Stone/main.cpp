#include <iostream>

using namespace std;

int main()
{
    int n, m, k, q, v[20][20] = {0}, p = 0, fp = 1, fn = 1;
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        for (int l = 1; l <= n; ++l)
            v[l][y] = 1;
        for (int l = 1; l <= m; ++l)
            v[x][l] = 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i][j] == 0)
                ++p;
    n = q;
    if (n < p)
        swap(n, p);
    if (p == 0)
        cout << 0;
    else {
        for (int i = 1; i <= max(n - p, 1); ++i)
            fp = fp * i;
        for (int i = 1; i <= n; ++i)
            fn = fn * i;
        cout << fn / fp;
    }
    return 0;
}
