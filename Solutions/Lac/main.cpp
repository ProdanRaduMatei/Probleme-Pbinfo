#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("lac.in");
ofstream fout("lac.out");

int n, m, v[1002][1002], nri, nrp, k;
int dl[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

void bt(int l, int c) {
    v[l][c] = 0;
    int lin, col;
    for (int i = 0; i < 4; ++i) {
        lin = l + dl[i];
        col = c + dc[i];
        if (lin == 0 || lin == n + 1 || col == 0 || col == m + 1)
            k = 1;
        if (lin > 0 && lin <= n && col > 0 && col <= m && v[lin][col] == 1)
            bt(lin, col);
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i][j] == 1) {
                k = 0;
                bt(i, j);
                if (k == 1)
                    ++nrp;
                else
                    ++nri;
            }
        }
    }
    fout << nri << " " << nrp;
    return 0;
}
