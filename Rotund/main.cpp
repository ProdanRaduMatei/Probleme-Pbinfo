#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("rotund.in");
ofstream fout("rotund.out");

int rotund(int n) {
    int c = n, cn = 0, p = 1, m = n, pp;
    while (c) {
        p = p * 10;
        ++cn;
        c = c / 10;
    }
    p = p / 10;
    for (int i = 1; i <= cn; ++i) {
        pp = m / p % 10;
        m = m - pp * p;
        m = m * 10;
        m = m + pp;
    }
    cout << m << " ";
    if (m == n)
        return 1;
    return 0;
}

int main()
{
    int n, v[51], c = 0, r[51];
    fin >> n;
    for (int i = 1; i <= n; ++i)
        if (rotund(v[i]) == 1) {
            ++c;
            r[c] = v[i];
        }
    fout << c << endl;
    for (int i = 1; i <= c; ++i)
        fout << r[i] << " ";
    return 0;
}
