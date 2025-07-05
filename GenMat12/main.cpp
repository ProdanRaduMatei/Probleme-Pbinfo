#include <iostream>

using namespace std;

int main()
{
    int n, k, v[25][25];
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= k; ++j)
            v[i][j] = 1;
    for (int i = 1; i <= k; ++i)
        for (int j = k + 1; j <= n; ++j)
            v[i][j] = 2;
    for (int i = k + 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            v[i][j] = 3;
    for (int i = k + 1; i <= n; ++i)
        for (int j = k + 1; j <= n; ++j)
            v[i][j] = 4;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
