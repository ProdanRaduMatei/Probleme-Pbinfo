#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("pavaj.in");
ofstream fout("pavaj.out");

int n, m, k;
int s[1001][1001];

int main()
{
    fin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int a;
            fin >> a;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= k; ++i) {
        int l1, c1, l2, c2;
        fin >> l1 >> c1 >> l2 >> c2;
        int lin1, col1, lin2, col2;
        lin1 = min(l1, l2);
        col1 = min(c1, c2);
        lin2 = max(l1, l2);
        col2 = max(c1, c2);
        int nrdale;
        nrdale = s[lin2][col2] - s[lin1 - 1][col2] - s[lin2][col1 - 1] + s[lin1 - 1][col1 - 1];
        if (nrdale == 0)
            fout << "0\n";
        else
            if (nrdale == (lin2 - lin1 + 1) * (col2 - col1 + 1))
                fout << "1\n";
            else
                fout << "2\n";
    }
    return 0;
}
