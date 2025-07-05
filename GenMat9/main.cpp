#include <iostream>

using namespace std;

int main()
{
    int n, v[16][16];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == 1 || i == n || j == 1 || j == n)
                v[i][j] = i + j;
            else if (i != 1 && i != n && j != 1 && j != n)
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
