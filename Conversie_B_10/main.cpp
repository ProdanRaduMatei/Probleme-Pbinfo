#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("conversie_b_10.in");
ofstream fout("conversie_b_10.out");

int main()
{
    long long n, b, m = 0, c, cn = 0, p,x;
    fin >> n >> b;
    c = n;
    while (c) {
        c = c / 10;
        ++cn;
    }
    p = 0;
    while (n) {
        x = 1;
        for (int i = 0; i < p; ++i)
            x = x * b;
        m = m + (n % 10) * x;
        n = n / 10;
        ++p;
    }
    fout << m;
    return 0;
}
