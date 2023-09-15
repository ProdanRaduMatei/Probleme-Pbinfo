#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("moscraciun.in");
ofstream fout("moscraciun.out");

int v[101][101], S[5000] = {0}, M[5000] = {0}, X[5000], Y[5000];

void fil(int i, int j, int c) {
    S[c] = S[c] + v[i][j];
    if (M[c] < v[i][j]) {
        M[c] = v[i][j];
        X[c] = i;
        Y[c] = j;
    }
    v[i][j] = 10;
    if (v[i - 1][j] != 0 && v[i - 1][j] != 10)
        fil(i - 1, j, c);
    if (v[i + 1][j] != 0 && v[i + 1][j] != 10)
        fil(i + 1, j, c);
    if (v[i][j - 1] != 0 && v[i][j - 1] != 10)
        fil(i, j - 1, c);
    if (v[i][j + 1] != 0 && v[i][j + 1] != 10)
        fil(i, j + 1, c);
}

int main()
{
    int n, m, c = 1, s = 0, p;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        cin >> v[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i][j] != 0) {
                M[c] = v[i][j];
                fil(i, j, c);
                ++c;
            }
    for (int i = 1; i < c; ++i)
        if (s < S[i]) {
            s = S[i];
            p = i;
        }
    cout << M[p] << " " << X[p] << " " << Y[p];
    return 0;
}
