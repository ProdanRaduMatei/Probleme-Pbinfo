#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("lincol.in");
ofstream fout("lincol.out");

int main()
{
    int n, m, v[101][101], p, k;
    char c;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        v[i][0] = 0;
    for (int j = 1; j <= m; ++j)
        v[0][j] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            fin >> v[i][j];
            v[0][j] = v[0][j] + v[i][j];
            v[i][0] = v[i][0] + v[i][j];
        }
    fin >> p;
    for (int i = 1; i <= p; ++i) {
        fin >> c >> k;
        if (c == 'L')
            fout << v[k][0] << endl;
        else
            fout << v[0][k] << endl;
    }
    return 0;
}
