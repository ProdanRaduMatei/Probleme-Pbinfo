#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("matrice4.in");
ofstream fout("matrice4.out");

int suma(int n, int x[101][101], int p) {
    int s = 0;
    for (int i = 1; i <= n; ++i)
        s = s + x[p][i];
    return s;
}

int main()
{
    int n, x[101][101];
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> x[i][j];
    for (int i = 1; i <= n; ++i)
        if (suma (n, x, i) % 2 == 0)
            fout << i << " ";
    return 0;
}
