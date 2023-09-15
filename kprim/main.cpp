#include <bits/stdc++.h>

using namespace std;

ifstream fin("kprim.in");
ofstream fout("kprim.out");

long long nrprim(long long x) {
    if (x <= 1)
        return 0;
    if (x % 2 == 0 && x != 2)
        return 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int main()
{
    long long n, m, ap = 0, p = 1;
    fin >> n;
    for (long long i = 1; i <= 10000000000; ++i) {
        if (nrprim(i) == 1) {
            p = i;
            ++ap;
        }
        if (ap == n + 1)
            break;
    }
    fout << p * p;
    return 0;
}
