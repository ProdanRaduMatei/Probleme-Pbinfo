#include <iostream>

using namespace std;

int main()
{
    int v[1001], c = 0, d = 0, n, m, p, e;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        v[i] = i;
        e = v[i];
        while (e % 5 == 0 || e % 2 == 0) {
            if (e % 5 == 0) {
                ++c;
                e = e / 5;
            }
            if (e % 2 == 0) {
                ++d;
                e = e / 2;
            }
        }
    }
    if (d < c)
        m = d;
    else
        m = c;
    c = 0;
    d = 0;
    for (int i = 1; i <= n; ++i) {
        while (v[i] % 5 == 0 && c < m) {
            v[i] = v[i] / 5;
            ++c;
        }
        while (v[i] % 2 == 0 && d < m) {
            v[i] = v[i] / 2;
            ++d;
        }
        if (d == m && c == m)
            break;
    }
    p = 1;
    for (int i = 1; i <= n; ++i)
        p = (p * v[i]) % 10;
    cout << p;
    return 0;
}
