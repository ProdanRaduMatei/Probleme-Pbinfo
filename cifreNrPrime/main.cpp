#include <iostream>

using namespace std;

int nrc(long long x) {
    int c = 0;
    while (x) {
        x = x / 10;
        ++c;
    }
    return c;
}

bool prim(long long x) {
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
    int n, c = 0;
    long long x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (prim(x) == 1)
            c = c + nrc(x);
    }
    cout << c;
    return 0;
}
