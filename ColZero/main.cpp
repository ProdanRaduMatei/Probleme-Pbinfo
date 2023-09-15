#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("colzero.in");
ofstream fout("colzero.out");

int main()
{
    int n, m, v[11][11], cnt = 0, c;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    for (int j = 1; j <= m; ++j) {
        c = 0;
        for (int i = 1; i <= n; ++i) {
            if (v[i][j] == 0)
                ++c;
        }
        if (c == n)
            ++cnt;
    }
    fout << cnt;
    return 0;
}
