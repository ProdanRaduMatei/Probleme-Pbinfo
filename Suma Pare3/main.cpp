#include <iostream>

using namespace std;

int main()
{
    int n, m, s = 0, v[101][101], c[1001] = {0};
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            if (v[i][j] % 2 == 0 && c[v[i][j]] == 0) {
                s = s + v[i][j];
                c[v[i][j]] = 1;
            }
        }
    cout << s;
    return 0;
}
