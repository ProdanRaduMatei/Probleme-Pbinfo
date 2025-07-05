#include <iostream>

using namespace std;

int main()
{
    int n, v[21][21], c = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> v[i][j];
    ///linia de sus
    if (v[1][1] > v[1][2] && v[1][1] > v[2][1])
        ++c;
    for (int i = 2; i < n; ++i)
        if (v[1][i] > v[1][i - 1] && v[1][i] > v[1][i + 1] && v[1][i] > v[2][i])
            ++c;
    if (v[1][n] > v[1][n - 1] && v[1][n] > v[2][n])
        ++c;
    ///linia de jos
    if (v[n][1] > v[n][2] && v[n][1] > v[n - 1][1])
        ++c;
    for (int i = 2; i < n; ++i)
        if (v[n][i] > v[n][i - 1] && v[n][i] > v[n][i + 1] && v[n][i] > v[n - 1][i])
            ++c;
    if (v[n][n] > v[n][n - 1] && v[n][n] > v[n - 1][n])
        ++c;
    ///linia din dreapta
    for (int i = 2; i < n; ++i)
        if (v[i][1] > v[i - 1][1] && v[i][1] > v[i + 1][1] && v[i][1] > v[i][2])
            ++c;
    ///linia din stanga
    for (int i = 2; i < n; ++i)
        if (v[i][n] > v[i - 1][n] && v[i][n] > v[i + 1][n] && v[i][n] > v[i][n - 1])
            ++c;
    for (int i = 2; i < n; ++i)
        for (int j = 2; j < n; ++j)
            if (v[i][j] > v[i - 1][j] && v[i][j] > v[i + 1][j] && v[i][j] > v[i][j - 1] && v[i][j] > v[i][j + 1])
                ++c;
    cout << c;
    return 0;
}
