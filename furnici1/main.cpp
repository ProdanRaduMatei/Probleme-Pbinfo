#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("furnici1.in");
ofstream fout("furnici1.out");

int tip1, tip2, k1, k2, n, a, b, c, v[501][501], k, neg, ok, nr, d, x1, x2, enr, Max, l, poz;
char sens;

int main() {
    fin >> l >> n;
    k = 0;
    Max = 0;
    for (int i = 1; i <= n; ++i) {
        fin >> poz >> sens;
        if (sens == 'S')
            k = poz;
        else
            k = l - poz;
        if (k > Max)
            Max = k;
    }
    fout << Max;
    return 0;
}
