#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("plopi2.in");
ofstream fout("plopi2.out");

int n, c[101], m = 10000, nct, s;

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> c[i];
        if (c[i] < m)
            m = c[i];
        if (c[i] > m) {
            s = s + c[i] - m;
            c[i] = m;
            ++nct;
        }
    }
    fout << nct << " " << s;
    return 0;
}
