#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, M = 0, a, m, d;
    cin >> n >> a;
    M = a;
    m = a;
    for (i = 2; i <= n; ++i) {
        cin >> a;
        if (a < m)
            m = a;
        if (a > M)
            M = a;
    }
    d = __gcd(m, M);
    m = m / d;
    M = M / d;
    cout << m << "/" << M;
    return 0;
}
