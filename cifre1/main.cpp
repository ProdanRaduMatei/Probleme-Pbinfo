#include <iostream>

using namespace std;

int main()
{
    int n, m = 0, M = 0, u;
    long long x, c;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        c = x;
        while (c) {
            u = c % 10;
            c = c / 10;
        }
        if (u == m)
            if (x > M)
                M = x;
        if (u > m) {
            m = u;
            M = x;
        }
    }
    cout << M;
    return 0;
}
