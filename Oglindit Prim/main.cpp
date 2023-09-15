#include <iostream>

using namespace std;

int prim(long long x) {
    if (x <= 1)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (long long d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int main()
{
    long long n, s = 0, x, o = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        o = 0;
        int p = 1, cx = x;
        while (cx) {
            o = o * 10 + cx % 10;
            cx = cx / 10;
        }
        if (prim(o))
            s = s + x;
    }
    cout << s;
    return 0;
}
