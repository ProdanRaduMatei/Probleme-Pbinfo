#include <iostream>

using namespace std;

int sdiv(int n)
{
    int d, rez = 0;
    for (d = 1; d * d <= n; ++d) {
        if (n % d == 0)
            rez = rez + d + n / d;
    }
    return rez;
}

int main()
{
    int n, m;
    cin >> n;
    m = 2 * n;
    if (sdiv(n) == m)
        cout << n << " este perfect";
    else
        cout << n << " nu este perfect";
    return 0;
}
