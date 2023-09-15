#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("maxminmatrice.in");
ofstream fout("maxminmatrice.out");

int main()
{
    int n, m, v[25][25], M = 0;
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
        v[i][0] = 1000;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            fin >> v[i][j];
            if (v[i][j] < v[i][0])
                v[i][0] = v[i][j];
        }
    for (int i = 1; i <= n; ++i)
        if (v[i][0] > M)
            M = v[i][0];
    fout << M;
    return 0;
}
