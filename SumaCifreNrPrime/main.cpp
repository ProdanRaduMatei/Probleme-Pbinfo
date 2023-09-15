#include <iostream>

using namespace std;

int scifre(long long x) {
    int s = 0;
    while (x) {
        s = s + x % 10;
        x = x / 10;
    }
    return s;
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
    int n, s = 0;
    long long x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (prim(x) == 1)
            s = s + scifre(x);
    }
    cout << s;
    return 0;
}
