#include <iostream>

using namespace std;

int main()
{
    long long n, m, c1[20], nc1 = 0, c2[20], nc2 = 0, mn = 100, mx = -1, x;
    cin >> n >> m;
    if (n == 0)
        c1[++nc1] = 0;
    else
        while (n) {
            c1[++nc1] = n % 10;
            n = n / 10;
        }
    if (m == 0)
        c2[++nc2] = 0;
    else
        while (m) {
            c2[++nc2] = m % 10;
            m = m / 10;
        }
    for (int i = 1; i <= nc1; ++i)
        for (int j = 1; j <= nc2; ++j) {
            x = 10 * c1[i] + c2[j];
            if (x > mx && x < 100)
                mx = x;
            if (x < mn && x > 9)
                mn = x;
            x = 10 * c2[j] + c1[i];
            if (x > mx && x < 100)
                mx = x;
            if (x < mn && x > 9)
                mn = x;
        }
    cout << mn << " " << mx;
    return 0;
}
