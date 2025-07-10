#include <iostream>

using namespace std;

long long c[1000001];

int main()
{
    int n, m, v[101][101], M = 0, cnt  = 0, x = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            ++c[v[i][j]];
            if (v[i][j] > M)
                M = v[i][j];
        }
    }
    for (int i = 0; i <= M; ++i)
        if (cnt <= c[i]) {
            cnt = c[i];
            x = i;
        }
    cout << x;
    return 0;
}
