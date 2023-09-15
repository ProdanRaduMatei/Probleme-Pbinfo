#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("matrice6.in");
ofstream fout("matrice6.out");

int main()
{
    int n, v[101][101], M = 0, m = 1000000000;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            fin >> v[i][j];
            if (v[i][j] > M)
                M = v[i][j];
            if (v[i][j] < m)
                m = v[i][j];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (v[i][j] == M)
                v[i][0] = 1;
    for (int i = 1; i <= n; ++i)
        if (v[i][0] == 1)
            for (int j = 1; j <= n; ++j)
                v[i][j] = v[i][j] + m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            fout << v[i][j] << " ";
        fout << endl;
    }
    return 0;
}
