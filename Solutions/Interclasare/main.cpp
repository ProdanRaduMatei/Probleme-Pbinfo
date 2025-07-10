#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("Interclasare.in");
ofstream fout("interclasare.out");

int n, m;
long long a[100001], b[100001],i, j;
int main()
{
    fin >> n;
    for (i = 1; i <= n; ++i)
        fin >> a[i];
    fin >> m;
    for (j = 1; j <= m; ++j)
        fin >> b[i];
    i = 1;
    j = 1;
    while (i <= n && j <= m) {
        if (a[i] < b[j]) {
            fout << a[i] << " ";
            ++i;
            if ((i + j) % 10 == 0)
                fout << "\n";
        }
        if (a[i] > b[j]) {
            fout << b[j] << " ";
            ++j;
            if ((i + j) % 10 == 0)
                fout << "\n";
        }
        if (a[i] == b[j]) {
            fout << a[i] << " ";
            ++i;
            if ((i + j) % 10 == 0)
                fout << "\n";
            fout << b[j] << " ";
            ++j;
            if ((i + j) % 10 == 0)
                fout << "\n";
        }
    }
    return 0;
}
