#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101][101], fr[10001] = {0}, s = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            if (fr[v[i][j]] == 0 && v[i][j] % 2 == 0)
                s = s + v[i][j];
            ++fr[v[i][j]];
        }
    cout << s;
    return 0;
}
