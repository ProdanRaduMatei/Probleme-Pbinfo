#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("prodmax.in");
ofstream fout("prodmax.out");

int main()
{
    int n, m, v[101][101], M = 0, c;
    fin >> n >> m;
    for (int j = 1; j <= m; ++j) {
        v[0][j] = 0;
        v[n + 1][j] = 0;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            fin >> v[i][j];
            if (v[i][j] == 0)
                v[n + 1][j] = 1;
            else if (v[i][j] == 2)
                ++v[0][j];
        }
    for (int j = 1; j <= m; ++j)
        if (v[0][j] > M && v[n + 1][j] == 0)
            M = v[0][j];
    for (int j = 1; j <= m; ++j)
        if (v[0][j] == M && v[n + 1][j] == 0)
            fout << j << " ";
    return 0;
}
