#include <iostream>

using namespace std;

int n, m, i, j, lp, lu, minp, minu, v[50][50];

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            cin >> v[i][j];
    minp = v[0][0];
    lp = 0;
    for (i = 1; i < n; ++i)
        if (v[i][0] < minp) {
            minp = v[i][0];
            lp = i;
    }
    minu = v[0][m - 1];
    lu = 0;
    for (i = 1; i < n; ++i)
        if (v[i][m - 1] < minu) {
            minu = v[i][m - 1];
            lu = i;
        }
    int t = v[lp][0];
    v[lp][0] = v[lu][m - 1];
    v[lu][m - 1] = t;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
