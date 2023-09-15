#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("arhipelag.in");
ofstream fout("arhipelag.out");

int dist(int x1, int y1, int x2, int y2)
{
    int rez1, rez2, r;
    rez1 = x1 - x2;
    if (rez1 < 0)
        rez1 = rez1 * (-1);
    rez2 = y1 - y2;
    if (rez2 < 0)
        rez2 = rez2 * (-1);
    r = rez1 + rez2;
    return r;
}

int n, m, v[305][305], cs[301], ls[301], cj[301], lj[301], k, c, l, q, s, M = 100000, C[301], L[301], cnt, d;
int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    k = 1;
    ///Determin marimea insulelor
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i][j] == 1) {
                cs[k] = i;
                ls[k] = j;
                c = j;
                l = i;
                ///Parcurg insula de la stanga la dreapta pe muchia de sus
                while (v[l][c] == 1 && c <= m) {
                    ++c;
                    v[l][c] = 2;
                }
                --c;
                ///Parcurg insula de sus pana jos pe muchia din dreapta
                while (v[l][c] == 1 && l <= n) {
                    ++l;
                    v[l][c] = 2;
                }
                cj[k] = l - 1;
                lj[k] = c;
                ++k;
            }
        }
    }
    q = k;
    for (int i = 1; i <= n; ++i)
        L[i] = -1;
    for (int j = 1; j <= m; ++j)
        C[j] = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i][j] == 0) {
                s = 0;
                for (k = 0; k < q; ++k) {
                    d = min (dist(i, j, cs[k], ls[k]), dist(i, j, cj[k], lj[k]));
                    s = s + d;
                }
                if (s == M) {
                    ++cnt;
                    C[cnt] = j;
                    L[cnt] = i;
                }
                if (s < M) {
                    c = j;
                    l = i;
                    for (int x = 0; x <= cnt; ++x)
                        C[x] = L[x] = -1;
                    cnt = 1;
                    C[cnt] = j;
                    L[cnt] = i;
                }
            }
        }
    }
    if (cnt == 1)
        fout << L[cnt] << " " << C[cnt];
    else {
        fout << L[cnt] << " " << C[cnt];
    }
    return 0;
}
