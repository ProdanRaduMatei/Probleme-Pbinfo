#include <iostream>

using namespace std;

int main()
{
    int n, m;
    long long v[101][101];
    cin >> n >> m;
    for (int j = 1; j <= m; ++j)
        v[0][j] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 0)
                v[0][j] = 0;
        }
    for (int j = 1; j <= m; ++j)
        if (v[0][j] == 0) {
            for (int k = j; k < m; ++k)
                for (int i = 0; i <= n; ++i)
                    v[i][k] = v[i][k + 1];
            --j;
            --m;
        }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
