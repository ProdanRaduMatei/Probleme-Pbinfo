#include <iostream>

using namespace std;

int s[101], maxx[101];

int main()
{
    int n, m, v[101][101];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            s[i] = s[i] + v[i][j];
            if (v[i][j] > maxx[i])
                maxx[i] = v[i][j];
        }
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i] - maxx[i];
        cout << s[i] << " ";
    }
    return 0;
}
