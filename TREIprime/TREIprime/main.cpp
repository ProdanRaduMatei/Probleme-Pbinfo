#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int x , y , n , m , p , q;
    cin >> x >> y;
    int d = 2;
    while (x % d)
        d++;
    n = x / d;
    m = y / (d - 1);
    long long int delta = (n + 1 - m) * (n + 1 - m) - 4 * n;
    long long int r = sqrt(delta);
    p = (n + 1 - m - r) / 2;
    q = (n + 1 - m + r) / 2;
    cout << d << ' ' << p << ' ' << q;
    return 0;
}
