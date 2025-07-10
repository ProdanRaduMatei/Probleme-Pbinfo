#include <bits/stdc++.h>

using namespace std;

int n, cx;

int cb(int st, int dr)
{
    int m = (st + dr) / 2, s = m, x = m;
    while (x)
        if (x >= 2 && x <= 5) {
            ++s;
            x = 0;
        }
        else {
            x /= 3;
            s += x;
        }
    if (2 * s == n)
        return m;
    else
        if (2 * s < n)
            return cb(m + 1, dr);
        else
            return cb(st, m - 1);
}

int main() {
    ifstream f("croseta.in");
    f >> n;
    ofstream g("croseta.out");
    g << cb(2, n);
    return 0;
}