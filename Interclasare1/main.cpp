#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("interclasare1.in");
ofstream fout("interclasare1.out");

int main()
{
    int n, m, v[100001], w[100001], i, j, cnt = 0;
    fin >> n;
    for (i = 1; i <= n; ++i)
        fin >> v[i];
    fin >> m;
    for (j = 1; j <= m; ++j)
        fin >> w[j];
    i = 1;
    j = 1;
    while (i <= n && j <= m) {
        if (v[i] < w[j]) {
            fout << v[i] << " ";
            ++cnt;
            if (cnt % 10 == 0)
                fout << endl;
            ++i;
        }
        else if (v[i] > w[j]) {
                fout << w[j] << " ";
                ++cnt;
                if (cnt % 10 == 0)
                    fout << endl;
                ++j;
            }
        else if (v[i] == w[j]) {
            fout << v[i] << " ";
            ++cnt;
            if (cnt % 10 == 0)
                fout << endl;
            ++i;
            ++j;
        }
    }
    if (i > n)
        while (j <= m) {
            fout << w[j] << " ";
            ++cnt;
            if (cnt % 10 == 0)
                fout << endl;
            ++j;
        }
    else
        while (i <= n) {
            fout << v[i] << " ";
            ++cnt;
            if (cnt % 10 == 0)
                fout << endl;
            ++i;
        }
    return 0;
}
