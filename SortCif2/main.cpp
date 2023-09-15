#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sortcif2.in");
ofstream fout("sortcif2.out");

int main()
{
    int n, v[101], c[101], m;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        m = v[i];
        while (m >= 10)
            m = m / 10;
        c[i] = m;
    }
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (c[i] > c[j]) {
                swap (c[i], c[j]);
                swap (v[i], v[j]);
            }
    for (int i = 1; i <= n; ++i)
        fout << v[i] << " ";
    return 0;
}
