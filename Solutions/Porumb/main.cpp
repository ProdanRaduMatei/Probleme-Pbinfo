#include <bits/stdc++.h>
 
using namespace std;

ifstream fin("porumb.in");
ofstream fout("porumb.out");

long long n, m, x, nr;

int main()
{
    fin >> n >> x;
    fout << (n + 1) / 2 << "\n";
    m = n;
    while (m > 0) {
        ++nr;
        m /= 2;
    }
    fout << nr << "\n";
    while (x % 2 == 0) {
        x /= 2;
        ++m;
    }
    fout << m + 1 << "\n";
    m = 1;
    while (m * 2 <= n)
        m *= 2;
    fout << m << "\n";
    fout.close();
    fin.close();
    return 0;
}