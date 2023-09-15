#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("traversare.in");
ofstream fout("traversare.out");

int n, m, C, x, y, ic, sc;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool inmat(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m)
        return 0;
    return 1;
}

int main()
{
    fin >> n >> m;
    int a[n + 5][m + 5], c[2][n + m];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> a[i][j];
    for (int i = 1; i <= m; ++i)
        if (a[1][i] == 0) {
            if (ic == 0)
                ++ic;
            ++sc;
            c[0][sc] = 1;
            c[1][sc] = i;
            a[1][i] = 1;
        }
    while (ic < sc) {
        for (int i = 0; i <= 3; ++i) {
            x = c[0][ic] + dx[i];
            y = c[1][ic] + dy[i];
            if (inmat(x, y))
                if (a[x][y] == 0) {
                    ++sc;
                    c[0][sc] = x;
                    c[1][sc] = y;
                    a[x][y] = a[c[0][ic]][c[1][ic]] + 1;
                }
        }
        ++ic;
    }
    C = n * m + 1;
    for (int i = 1; i <= m; ++i)
        if (a[n][i] < C && a[n][i] != 1 && a[n][i] != 0)
            C = a[n][i];
    fout << C;
    return 0;
}
