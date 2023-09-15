#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("halfsort.in");
ofstream fout("halfsort.out");
int n, v[101], p[55], m[55], j = 1, k = 1, a, b;
int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        if (i % 2 == 0) {
            p[j] = v[i];
            ++j;
        }
        else {
            m[k] = v[i];
            ++k;
        }
    }
    a = j - 1;
    b = k - 1;
    j = 1;
    --k;
    sort(p + 1, p + 1 + a);
    sort(m + 1, m + 1 + b);
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            fout << p[j] << " ";
            ++j;
        }
        else {
            fout << m[k] << " ";
            --k;
        }
    }
    return 0;
}
