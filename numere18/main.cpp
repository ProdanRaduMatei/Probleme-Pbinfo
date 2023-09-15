#include <cmath>
#include <fstream>

using namespace std;

ifstream fin("numere18.in");
ofstream fout("numere18.out");

int C;
long long n, m, poz, pt, ut, s;

int main()
{
    fin >> C;
    if (C == 1) {
        fin >> n;
        pt = n * (n - 1) / 2 + 1;
        ut = pt + n - 1;
        s = (pt + ut) * n / 2;
        fout << s;
    }
    if (C == 2) {
        fin >> m;
        n = (1 + int(sqrt(8 * m - 7))) / 2;
        pt = n * (n - 1) / 2 + 1;
        poz = m - pt + 1;
        fout << n << " " << poz;
    }
    return 0;
}
