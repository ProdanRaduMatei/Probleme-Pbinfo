#include <iostream>

using namespace std;

long long impar(long long x) {
    long long y = 0, p = 1;
    while (x) {
        if ((x % 10) % 2 == 1) {
            y = y + x % 10 * p;
            p = p * 10;
        }
        x = x / 10;
    }
    return y;
}

long long par(long long x) {
    long long y = 0, p = 1;
    while (x) {
        if ((x % 10) % 2 == 0) {
            y = y + x % 10 * p;
            p = p * 10;
        }
        x = x / 10;
    }
    return y;
}

int main()
{
    long long a, b, n, m;
    cin >> a >> b;
    if (a % 2 == 0)
        n = par(a);
    else
        n = impar(a);
    if (b % 2 == 0)
        m = par(b);
    else
        m = impar(b);
    if (n == m)
        cout << max(a, b);
    else {
        if (max(n, m) == n)
            cout << a;
        else if (max(n, m) == m)
            cout << b;
    }
    return 0;
}
