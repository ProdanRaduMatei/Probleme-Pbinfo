#include <iostream>
#include <algorithm>

using namespace std;

int n, m, v[100][100], x[100];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            x[j] = v[i][j];
        }
        sort(x + 1, x + n + 1);
        for (int j = 1; j <= m; ++j) {
            v[i][j] = x[j];
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
