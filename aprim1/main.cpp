#include <bits/stdc++.h>

using namespace std;

int prim(int x) {
    if (x <= 1)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int aprim(int x) {
    if (x <= 3)
        return 0;
    for (int d = 2; d * d <= x; ++d)
        if (x % d == 0 && prim(d) && prim(x / d) && d != x / d)
            return 1;
    return 0;
}

int main()
{
    int n, x, c = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (aprim(x))
            ++c;
    }
    cout << c;
    return 0;
}
