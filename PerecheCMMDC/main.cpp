#include <iostream>

using namespace std;

int main()
{
    int n, m = 0, sm = 0, s = 0, x, y, a, b, ca, cb, r;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        ca = a;
        cb = b;
        s = ca + cb;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        if (a == m)
            if (sm < s) {
                m = a;
                sm = s;
                x = ca;
                y = cb;
            }
        if (a > m) {
            m = a;
            sm = s;
            x = ca;
            y = cb;
        }
    }
    cout << x << " " << y;
    return 0;
}
