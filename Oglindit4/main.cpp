#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, cnt = 0, a, o = 0, ca, u;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a;
        ca = a;
        o = 0;
        while (ca > 0) {
            u = ca % 10;
            o = o * 10 + u;
            ca = ca / 10;
        }
        if (__gcd(a, o) == 1)
            ++cnt;
    }
    cout << cnt;
    return 0;
}
