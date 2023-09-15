#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cioc.in");
ofstream fout("cioc.out");

int n, k, c, kf;
long long v[100002], a[100002], maxk;

int main()
{
    fin >> c >> n >> k;
    for (int i = 0; i < n; ++i) {
        fin >> v[i];
        a[i] = v[i];
    }
    sort(a, a + n);
    while (a[k] == a[k - 1] && k < n)
        ++k;
    kf = k;
    maxk = a[k - 1];
    if (c == 1)
        fout << kf;
    else {
        for (int i = 0; i < n; ++i) {
            fout << v[i] << " ";
            if (v[i] <= maxk)
                fout << 2 * v[i] << " ";
        }
    }
    return 0;
}
