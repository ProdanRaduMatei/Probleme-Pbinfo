#include <iostream>

using namespace std;

int main()
{
    int n, v[16][16];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        v[i][1] = 1;
    for (int j = 1; j <= n; ++j)
        v[n][j] = j;
    for (int i = n - 1; i >= 1; --i)
        for (int j = 2; j <= n; ++j)
            v[i][j] = v[i][j - 1] + v[i + 1][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
