#include <iostream>

using namespace std;

int main()
{
    int n, m, v[25][25], p;
    cin >> n >> m;
    p = n * m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            v[i][j] = p;
            --p;
        }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
