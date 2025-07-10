#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, cnt = 0, a = 0, b = 0, cn, i, p, m;
    cin >> n;
    cn = n;
    while (cn > 0) {
        cn = cn / 10;
        ++cnt;
    }
    if (cnt % 2 != 0) {
        p = cnt / 2;
        m = cnt - p;
        if (m > p)
            swap(m, p);
        for (i = 1, p = 1; i <= m; ++i, p = p * 10) {
            b = b + n % 10 * p;
            n = n / 10;
        }
        n = n / 10;
        for (i = m + 1, p = 1; i <= cnt; ++i, p = p * 10) {
            a = a + n % 10 * p;
            n = n / 10;
        }
    }
    else {
        for (i = 1, p = 1; i <= cnt / 2; ++i, p = p * 10) {
            b = b + n % 10 * p;
            n = n / 10;
        }
        for (i = cnt / 2, p = 1; i <= cnt; ++i, p = p * 10) {
            a = a + n % 10 * p;
            n = n / 10;
        }
    }
    cout << __gcd(a, b);
    return 0;
}
