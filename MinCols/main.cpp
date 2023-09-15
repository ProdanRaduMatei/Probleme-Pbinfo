#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("mincols.in");
ofstream fout("mincols.out");

int main()
{
    int n, v[51][51];
    fin >> n;
    for (int j = 1; j <= n; ++j)
        v[0][j] = 1000;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            fin >> v[i][j];
            if (v[i][j] < v[0][j])
                v[0][j] = v[i][j];
        }
    for (int j = 1; j <= n; ++j)
        fout << v[0][j] << " ";
    return 0;
}
