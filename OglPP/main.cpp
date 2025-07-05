#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, nr = 0, n, k, r, ninv;
    cin >> a >> b;
    for (int i = 1; i <= 31623; ++i) {
        n = i * i;
        k = n;
        ninv = 0;
        while (n) {
            ninv = ninv * 10 + n % 10;
            n = n / 10;
        }
        r = sqrt(ninv);
        if (r * r == ninv && k >= a && k <= b)
            ++nr;
    }
    cout << nr;
    return 0;
}
