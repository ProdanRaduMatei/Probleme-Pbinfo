#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("razboi.in");
ofstream fout("razboi.out");

int main()
{
    int n, l, v[60000], i, a = 0, c = 0, u, s = 0, d;
    fin >> n >> l;
    for (i = 0; i < n; ++i)
        fin >> v[i];
    if (l == 1) {
        for (i = 0; i < n; ++i) {
            u = v[i] % 10;
            if (u % 2 == 0)
                ++a;
            else
                ++c;
        }
        fout << a << " " << c;
    }
    else {
        for (i = 0; i < n; ++i) {
            s = 0;
            for (d = 2; d * d <= v[i]; ++d) {
                if (v[i] % d == 0) {
                    s = s + d + v[i] / d;
                }
            }
            if (s % 2 == 0)
                ++a;
            else
                ++c;
        }
        fout << a << " " << c;
    }
    return 0;
}
