#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("matrice7.in");
ofstream fout("matrice7.out");

int main() {
    long long l, c, v[102][102], m = 0;
    fin >> l >> c;
    for (int j = 1; j <= c; ++j)
        v[0][j] = 999999999;
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= c; ++j)
        {
            fin >> v[i][j];
            if (v[i][j] > m)
                m = v[i][j];
            if (v[i][j] < v[0][j])
                v[0][j] = v[i][j];
        }
    for (int i = 1; i <= l; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (v[i][j] == m)
                fout << v[0][j] << " ";
            else
                fout << v[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}
