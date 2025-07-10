#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("iesire.in");
ofstream fout("iesire.out");

int n, m, v[102][102], x, y, b[102][102], ok;
int dl[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

void gol(int b[102][102]) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            b[i][j] = 0;
}

void bt(int l, int c, int p) {
    if (l == 1 || l == n || c == 1 || c == n) {
        fout << "da" << endl;
        ok = 1;
    }
    else {
        b[l][c] = p;
        ++p;
        int lin, col;
        for (int i = 0; i < 4; ++i) {
            lin = l + dl[i];
            col = c + dc[i];
            if (v[lin][col] == 0 && b[lin][col] == 0)
                bt(lin, col, p);
        }
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 0; i <= n + 1; ++i)
        v[i][0] = v[i][n + 1] = v[0][i] = v[n + 1][i] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> v[i][j];
    for (int i = 1; i <= m; ++i) {
        fin >> x >> y;
        ok = 0;
        bt(x, y, 1);
        if (ok == 0)
            fout << "nu" << endl;
        gol(b);
    }
    return 0;
}
