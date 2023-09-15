#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("soarece.in");
ofstream fout("soarece.out");

int n, m, v[12][12], ls, cs, lb, cb, nt;
int dl[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

void bt(int l, int c, int p) {
    for (int i = 0; i < 4; ++i) {
        int lin = l + dl[i];
        int col = c + dc[i];
        if (lin > 0 && lin <= n && col > 0 && col <= m && v[lin][col] == 0) {
            if (lin == lb && col == cb)
                ++nt;
            else {
                v[lin][col] = p;
                bt(lin, col, p + 1);
                v[lin][col] = 0;
            }
        }
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    fin >> ls >> cs >> lb >> cb;
    v[ls][cs] = 1;
    bt(ls, cs, 2);
    fout << nt;
    return 0;
}
