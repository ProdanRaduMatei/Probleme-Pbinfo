#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("dreptunghi1.in");
ofstream fout("dreptunghi1.out");

int n, m, q, v[10002][10002], x, y, am;

int bt(int )

int main()
{
    fin >> n >> m >> q;
    for (int i = 0; i <= n + 1; ++i)
        v[i][0] = v[i][m + 1] = 1;
    for (int i = 0; i <= m + 1; ++i)
        v[0][i] = v[n + 1][i] = 1;
    for (int i = 1; i <= q; ++i) {
        fin >> x >> y;
        v[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int a = bt(i, j, 1, 1, 1, 1);
            if (a > am)
                am = a;
        }
    return 0;
}
