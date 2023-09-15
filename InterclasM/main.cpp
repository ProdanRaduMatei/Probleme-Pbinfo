#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("interclasm.in");
ofstream fout("interclasm.out");

int main()
{
    int n, a[100001], b[100001], c[200002], m;
    long long x;
    fin >> x >> n;
    int maxim = 0;
    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
        maxim = max(maxim, a[i]);
        ++c[a[i]];
    }
    fin >> m;
    for (int i = 1; i <= m; ++i) {
        fin >> b[i];
        maxim = max(maxim, b[i]);
        ++c[b[i]];
    }
    for (int i = 1; i <= maxim; ++i)
        if (c[i] == 1 && i % x == 0)
            fout << i << " ";
    return 0;
}
