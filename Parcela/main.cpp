#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("parcela.in");
ofstream fout("parcela.out");

int n, m, v[102][102], nr, amax, pmax, a;
int dl[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

void bt(int x, int y) {
    int l, c;
    v[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
        l = x + dl[i];
        c = y + dc[i];
        if (v[l][c] == 1) {
            ++a;
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
                ++nr;
                a = 1;
                bt(i, j);
                if (a > amax) {
                    amax = a;
                    pmax = nr;
                }
            }
    fout << nr << " " << amax << " " << pmax;
    return 0;
}
