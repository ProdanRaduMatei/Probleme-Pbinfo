#include <iostream>
#include <algorithm>

using namespace std;

int ndiv(int x) {
    int nr = 0;
    for (int i = 1; i * i <= x; ++i)
        if (x % i == 0)
            if (i * i == x)
                ++nr;
            else
                nr = nr + 2;
    return nr;
}

int main()
{
    int n, a, b, x, M = 0, m = 1000001, nrd;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        x = __gcd(a, b);
        nrd = ndiv(x);
        if (nrd % 2 == 0 && x > M)
            M = x;
        else if (nrd % 2 == 1 && x < m)
            m = x;
    }
    if (M == 0 || m == 1000001)
        cout << "NU EXISTA";
    else
        cout << M << " " << m;
    return 0;
}
