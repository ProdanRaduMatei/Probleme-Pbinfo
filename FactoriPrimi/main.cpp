#include <iostream>

using namespace std;

int main()
{
    long long n, m, nr1 = 1, nr2 = 1;
    cin >> n >> m;
    long long d;
    d = 2;
    while (d * d <= n) {
        int e = 0;
        while (n % d == 0) {
            n = n / d;
            ++e;
        }
        if (e > 0)
            nr1 = nr1 * d;
        ++d;
    }
    if (n > 1)
        nr1 = nr1 * n;
    d = 2;
    while (d * d <= m) {
        int e = 0;
        while (m % d == 0) {
            m = m / d;
            ++e;
        }
        if (e > 0)
            nr2 = nr2 * d;
        ++d;
    }
    if (m > 1)
        nr2 = nr2 * m;
    if (nr1 == nr2)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
