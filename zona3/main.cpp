#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("zona3.in");
ofstream fout("zona3.out");

int n, m, v[102][102], f[102][102], cn;
int dl[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

void mut(int x, int y) {
    int l, c;
    v[x][y] = cn;
    f[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
        l = x + dl[i];
        c = y + dc[i];
        if (f[l][c] == 1)
            mut(l, c);
    }
}

void bt(int x, int y) {
    int l, c;
    v[x][y] = 0;
    f[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        l = x + dl[i];
        c = y + dc[i];
        if (v[l][c] == 1) {
            ++cn;
            bt(l, c);
        }
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i][j] == 1) {
                cn = 1;
                bt(i, j);
                mut(i, j);
            }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            fout << v[i][j] << " ";
        fout << endl;
    }
    return 0;
}
