#include <bits/stdc++.h>

using namespace std;

ifstream fin("cod24.in");
ofstream fout("cod24.out");

int main()
{
    int n, a, b, c, d;
    fin >> n;
    a = n % 10;
    n = n / 10;
    b = n % 10;
    n = n / 10;
    c = n % 10;
    n = n / 10;
    d = n % 10;
    if (a < 9)
        ++a;
    if (b < 9)
        ++b;
    if (c < 9)
        ++c;
    if (d < 9)
        ++d;
    n = 0;
    n = d * 1000 + c * 100 + a * 10 + b;
    fout << n;
    return 0;
}
