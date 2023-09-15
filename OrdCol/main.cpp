#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101][101];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> v[i][j];
    for (int j = 1; j < m; ++j) {
        for (int k = j + 1; k <= m; ++k) {
            if (v[1][j] > v[1][k]) {
                int aux;
                for (int i = 1; i <= n; ++i) {
                    aux = v[i][j];
                    v[i][j] = v[i][k];
                    v[i][k] = aux;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
