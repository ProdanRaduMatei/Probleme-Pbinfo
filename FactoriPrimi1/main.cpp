#include <iostream>

using namespace std;

int main()
{
    long long n, b, p, d = 0, x, t, nr = 1;
    cin >> n;
    d = 2;
    while (n > 1) {
        p = 0;
        while (n % d == 0) {
            ++p;
            n = n / d;
        }
        if (p > 0)
            nr = nr * d;
        ++d;
        if (d * d > n)
            d = n;
    }
    cout << nr;
    return 0;
}
