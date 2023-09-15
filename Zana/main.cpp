#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("zana.in");
ofstream fout("zana.out");

int n, m, k, v[200][200], b[200][200], x, y, M, a;
int dl[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

void bt(int l, int c, int p) {
    int lin, col;
    b[l][c] = p;
    ++p;
    for (int i = 0; i < 4; ++i) {
        lin = l + dl[i];
        col = c + dc[i];
        if (lin >= 1 && lin <= n && col >= 1 && col <= m)
            bt(lin, col, p);
    }
}

int main()
{
    fin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        fin >> x >> y;
        ++v[x][y];
    }
    bt(n, 1, 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i][j] == M && b[i][j] != 0)
                ++a;
            if (v[i][j] > M && b[i][j] != 0)
                a = 1;
        }
    }
    fout << M << endl << a;
    return 0;
}
