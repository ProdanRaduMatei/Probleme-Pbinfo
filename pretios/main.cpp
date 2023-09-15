#include <bits/stdc++.h>

using namespace std;

unsigned long long start, stop;
unsigned long long a, b, i, nr, p = 1;

bool prim(long long x) {
    bool ok = true;
    long long i;
    if (x == 0 || x == 1)
        return false;
    for (i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            ok = false;
            break;
        }
    return ok;
}

int main()
{
    cin >> a >> b;
    start = log2(a) + 1;
    stop = log2(b);
    for (i = 1; i <= start; ++i)
        p = p * 2;
    if (prim(start))
        nr = nr + p - a;
    for (i = start; i < stop; ++i)
        if (prim(i + 1)) {
            nr = nr + p;
            p = p * 2;
        }
        else
            p = p * 2;
    if (prim(stop + 1))
        nr = nr + b - p + 1;
    cout << nr << " ";
    return 0;
}
