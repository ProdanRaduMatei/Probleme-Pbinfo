#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, v[10201], k, a[101][101];
    char c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n * m; ++i)
        cin >> v[i];
    sort (v + 1, v + 1 + n * m);
    if (c == '+') {
        k = 1;
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                a[i][j] = v[k];
                ++k;
            }
        }
    }
    else {
        k = n * m;
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                a[i][j] = v[k];
                --k;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
