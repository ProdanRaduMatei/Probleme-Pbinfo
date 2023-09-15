#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("matrice_div_et_imp.in");
ofstream fout("matrice_div_et_imp.out");

int n, v[101][101];

void DeI(int i, int j, int l) {
    if (l == 2)
        fout << v[i][j] << " " << v[i + 1][j + 1] << " " << v[i][j + 1] << " " << v[i + 1][j] << " ";
    else {
        DeI(i, j, l / 2);
        DeI(i + l / 2, j + l / 2, l / 2);
        DeI(i, j + l / 2, l / 2);
        DeI(i + l / 2, j, l / 2);
    }
}

int main()
{
    int l = 1;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        l = l * 2;
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= l; ++j)
            fin >> v[i][j];
    }
    DeI(1, 1, l);
    return 0;
}
