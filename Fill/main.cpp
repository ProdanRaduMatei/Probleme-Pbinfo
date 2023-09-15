#include <iostream>
#include <fstream>

using namespace std;

istream fin("fill.in");
ofstream fout("fill.out")

int v[101][101];

void fil(int i, int j, int c) {
    v[i][j] = c;
    if (v[i - 1][j] == 1)
        fil(i - 1, j, c);
    if (v[i + 1][j] == 1)
        fil(i + 1, j, c);
    if (v[i][j - 1] == 1)
        fil(i, j - 1, c);
    if (v[i][j + 1] == 1)
        fil(i, j + 1, c);
}

int main()
{
    int n, m, c = 0;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        fin >> v[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i][j] == 1) {
                ++c;
                fil(i, j, c + 1);
            }
    fout << c;
    return 0;
}
