#include <iostream>

using namespace std;

int nrdiv(int x) {
    int n = 0;
    for (int i = 1; i * i <= x; ++i)
        if (x % i == 0) {
            ++n;
            if (i * i < x)
                ++n;
        }
    return n;
}

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

int main()
{
    int n, f;
    long long s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> f;
        if (prim(f) == 0)
            if (nrdiv(f) % 2 == 1)
                s = s + 3 * f;
            else
                s = s + f;
    }
    cout << s;
    return 0;
}
