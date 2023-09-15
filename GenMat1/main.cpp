#include <iostream>

using namespace std;

int main()
{
    int n, m, v[25][25];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            v[i][j] = min(i, j);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
