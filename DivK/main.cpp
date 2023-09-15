#include <bits/stdc++.h>

using namespace std;

ifstream fin("divk.in");
ofstream fout("divk.out");

int main()
{
    int n, k, nrd, d, x;
    fin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        nrd = 0;
        fin >> x;
        for (d = 1; d * d <= x; ++d)
            if (x % d == 0)
                nrd = nrd + 2;
        if (d * d == x)
            ++nrd;
        if (nrd >= k)
            fout << x << " ";
    }
    return 0;
}
