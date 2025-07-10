#include <iostream>

using namespace std;

bool prim(int x) {
    if (x < 2)
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

int ogl(int x) {
    int o = 0;
    while (x) {
        o = o * 10 + x % 10;
        x = x / 10;
    }
    return o;
}

int main()
{
    int n, x, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (prim(ogl(x)) == 1)
            s = s + x;
    }
    cout << s;
    return 0;
}
