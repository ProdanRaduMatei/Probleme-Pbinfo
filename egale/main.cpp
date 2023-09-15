#include <iostream>

using namespace std;

int main()
{
    int t, a, b, x, u, cn, cnt, i, ci, ok, c;
    cin >> t;
    if (t == 1) {
        cin >> a >> b;
        for (i = a; i <= b; ++i) {
            ci = i;
            c = ci % 10;
            ok = 1;
            while (ci > 0) {
                u = ci % 10;
                ci = ci / 10;
                if (u != c)
                    ok = 0;
            }
            if (ok == 1)
                cout << i << " ";
        }
    }
    else {
        cin >> x;
        cn = 0;
        for (i = 1; cn <= x; ++i) {
            cnt = 0;
            ci = i;
            c = ci % 10;
            ok = 1;
            while (ci > 0) {
                u = ci % 10;
                ci = ci / 10;
                ++cnt;
                if (u != c)
                    ok = 0;
            }
            if (ok == 1)
                cout << i << " ";
            if (cnt > cn)
                cn = cnt;
        }
    }
    return 0;
}
