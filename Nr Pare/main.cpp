#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101][101], M = 0, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        v[i][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            if (v[i][j] % 2 == 0)
                ++v[i][0];
        }
        if (v[i][0] > M)
            M = v[i][0];
    }
    for (int i = 1; i <= n; ++i)
        if (v[i][0] == M)
            cout << i << " ";
    return 0;
}
