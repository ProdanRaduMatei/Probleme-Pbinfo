#include <iostream>

using namespace std;

int main()
{
    int n, v[21][21];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        v[i][1] = i;
    for (int j = 2; j <= n; ++j)
        v[n][j] = n;
    for (int j = 2; j <= n; ++j)
        for (int i = 1; i < n; ++i)
            v[i][j] = v[i][j - 1] + v[i + 1][j - 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
