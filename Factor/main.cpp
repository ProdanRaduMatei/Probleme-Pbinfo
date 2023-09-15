#include <iostream>

using namespace std;

int main()
{
    int n, k, pr, p, a, d, m, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        pr = pr * x;
    }
    a = pr;
    d = 2;
    m = 1;
    while (a > 1) {
        p = 0;
        while (a % d == 0) {
            a = a / d;
            ++p;
        }
        if (d > m && p > 0) {
            m = d;
            k = p;
        }
        d = 0;
    }
    cout << m;
    return 0;
}
