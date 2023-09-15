#include <iostream>
#include <algorithm>

using namespace std;

int caut(int n, int v[], int x) {
    int st = 1, dr = n, gasit = 0, mijl;
    while (st <= dr && gasit != 1) {
    mijl = (st + dr) / 2;
    if (v[mijl] == x)
        gasit = 1;
    else
        if (x < v[mijl])
            dr = mijl - 1;
        else
            st = mijl + 1;
    }
    if (st > dr)
        return 0;
    else
        return 1;
}

int n, x[100001], y[100001], z[100001], m = 0, ok, p;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    for (int i = 1; i <= n; ++i)
        cin >> y[i];
    for (int i = 1; i <= n; ++i)
        cin >> z[i];
    if (x[1] > m) {
        m = x[1];
        p = 1;
    }
    if (y[1] >= m) {
        m = y[1];
        p = 2;
        if (y[1] == m)
            ok = 1;
    }
    if (z[1] >= m) {
        m = z[1];
        p = 3;
        if (z[1] == m)
            ++ok;
    }
    if (ok == 2) {
        cout << x[1];
        return 0;
    }
    if (p == 1) {
        int i = 1;
        while (i <= n) {
            m = x[i];
            if (caut(n, y, m) == 1 && caut(n, z, m) == 1) {
                cout << m;
                return 0;
            }
            ++i;
            while (x[i] == m && i < n)
                ++i;
        }
        cout << "-1";
        return 0;
    }
    if (p == 2) {
        int i = 1;
        while (i <= n) {
            m = y[i];
            if (caut(n, x, m) == 1 && caut(n, z, m) == 1) {
                cout << m;
                return 0;
            }
            ++i;
            while (y[i] == m && i < n)
                ++i;
        }
        cout << "-1";
        return 0;
    }
    if (p == 3) {
        int i = 1;
        while (i <= n) {
            m = z[i];
            if (caut(n, x, m) == 1 && caut(n, y, m) == 1) {
                cout << m;
                return 0;
            }
            ++i;
            while (z[i] == m && i < n)
                ++i;
        }
        cout << "-1";
        return 0;
    }
    return 0;
}
