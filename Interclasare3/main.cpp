#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("interclasare3.in");
ofstream fout("interclasare3.out");

int main()
{
    int n, m, v[100000], w[100000], i, j, cnt = 0;
    fin >> n >> m;
    for (i = 1; i <= n; ++i)
        fin >> v[i];
    for (j = 1; j <= m; ++j)
        fin >> w[j];
    i = 1;
    j = m;
    while (i <= n && j >= 1) {
        if (v[i] < w[j] && v[i] % 2 == 0) {
            fout << v[i] << " ";
            ++i;
            ++cnt;
            if (cnt % 20 == 0)
                fout << endl;
        }
        else if (v[i] > w[j] && w[j] % 2 == 0) {
            fout << w[j] << " ";
            --j;
            ++cnt;
            if (cnt % 20 == 0)
                fout << endl;
        }
        else if (v[i] == w[j] && w[j] % 2 == 0) {
            fout << v[i] << " ";
            ++i;
            ++cnt;
            if (cnt % 20 == 0)
                fout << endl;
            fout << w[j] << " ";
            --j;
            ++cnt;
            if (cnt % 20 == 0)
                fout << endl;
        }
    }
    while (i <= n) {
        if (v[i] % 2 == 0) {
            fout << v[i] << " ";
            ++cnt;
            if (cnt % 20 == 0)
                fout << endl;
        }
        ++i;
    }
    while (j >= 1) {
        if (w[j] % 2 == 0) {
            fout << w[j] << " ";
            ++cnt;
            if (cnt % 20 == 0)
                fout << endl;
        }
        --j;
    }
    return 0;
}
