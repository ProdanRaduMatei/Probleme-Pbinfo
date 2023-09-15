#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("matrice5.in");
ofstream fout("matrice5.out");

int sub(int n, int x[101][101], int k) {
    int s = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i + j == k)
                s = s + x[i][j];
    return s;
}

int main()
{
    int n, x[101][101], s = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> x[i][j];
    for (int k = n; k > 1; --k)
        s = s + sub(n, x, k);
    fout << s;
    return 0;
}
