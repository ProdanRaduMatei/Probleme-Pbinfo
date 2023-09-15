#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("rotire.in");
ofstream fout("rotire.out");

int main()
{
    long long m, n, a[11][11], b[11][11];
    fin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            b[i][j] = a[j][n - i + 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            fout << b[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}
