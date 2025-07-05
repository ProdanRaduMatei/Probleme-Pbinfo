#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[10], b[10], i = 1, m, s = 0, j;
    cin >> n >> a[i] >> b[i];
    for (i = 2; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if (i == 2) {
            j = b[1] * b[2] / (__gcd(b[1], b[2]));
            m = j;
        }
        else {
            j = j * b[i] / (__gcd(j, b[i]));
            m = j;
        }
    }
    for (i = 1; i <= n; ++i)
        s = s + a[i] * (m / b[i]);
    j = __gcd(s, m);
    s = s / j;
    m = m / j;
    cout << s << " " << m;
    return 0;
}
