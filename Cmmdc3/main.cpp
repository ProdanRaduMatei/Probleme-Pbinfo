#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, v[1001], d1, d2, d, m;
    cin >> n;
    m = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    d1 = v[1];
    d2 = v[m + 1];
    for (int i = 1; i <= m; ++i)
        d1 = __gcd(d1, v[i]);
    for (int i = m + 1; i <= n; ++i)
        d2 = __gcd(d2, v[i]);
    d = __gcd(d1, d2);
    cout << d;
    return 0;
}
