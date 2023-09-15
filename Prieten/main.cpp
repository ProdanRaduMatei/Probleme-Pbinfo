#include <iostream>

using namespace std;

int sdiv(int x)
{
    int d, rez = 0;
    for (d = 1; d <= x / 2; ++d) {
        if (x % d == 0)
            rez = rez + d;
    }
    rez = rez + x;
    return rez;
}

int main()
{
    int a, b, n, m;
    cin >> a >> b;
    n = sdiv(a);
    m = sdiv(b);
    if (n == b && m == a)
        cout << "PRIETENE";
    else
        cout << "NU SUNT PRIETENE";
    return 0;
}
