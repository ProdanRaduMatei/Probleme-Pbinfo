#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cifpagini.in");
ofstream fout("cifpagini.out");

int n, p, v, S, x, t, k, a[1001], d, i, S1;

int main() {
    fin >> n >> p >> v;
    S += p;
    x = p + 1;
    while (k <= n - 1) {
        if (x % 2 != 0) {
            d = 3;
            t = 1;
            while (d * d <= x) {
                if (x % d == 0)
                    ++t;
                ++d;
            }
            if (t == 1) {
                ++k;
                a[k] = x;
            }
        }
        ++x;
    }
    for (i = 1; i <= n - 1; ++i)
        S += a[i];
    if (v == 1)
        fout << S;
    else {
        p = 1;
        x = S;
        k = 0;
        while (S) {
            p *= 10;
            ++k;
            S /= 10;
        }
        p /= 10;
        while (k) {
            S1 += k * (x - p + 1);
            --k;
            x = p - 1;
            p /= 10;
        }
        fout << S1;
    }
    return 0;
}
