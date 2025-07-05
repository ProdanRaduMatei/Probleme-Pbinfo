#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, d, m, n, p, q, x, y, a1, a2;
    cin >> a >> b >> c >> d;
    x = __gcd(a, b);
    a = a / x;
    b = b / x;
    x = __gcd(c, d);
    c = c / x;
    d = d / x;
    y = __gcd(d, b);
    if (y == 1)
        n = b * d;
    else
        n = y;
    a1 = n / b;
    a2 = n / d;
    m = a * a1 + c * a2;
    p = a * c;
    q = b * d;
    x = __gcd(n, m);
    n = n / x;
    m = m / x;
    x = __gcd(p, q);
    p = p / x;
    q = q / x;
    cout << m << " " << n << endl << p << " " << q;
    return 0;
}
