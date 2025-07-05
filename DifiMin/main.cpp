#include <iostream>

using namespace std;

int main()
{
    int n, a, b, d, m, D, M = 100000000;
    cin >> n;
    for (d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            m = n / d;
            if (m > d)
                D = m - d;
            else
                D = d - m;
            if (D < M) {
                a = d;
                b = m;
                M = D;
            }
        }
    }
    cout << a << " " << b;
    return 0;
}
