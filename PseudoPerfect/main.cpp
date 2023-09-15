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
    int n;
    cin >> n;
    if (sdiv(n) % n == 0)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
