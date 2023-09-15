#include <iostream>

using namespace std;

int main()
{
    int n, k, m, p, ec7, ec8, y, z, t, x;
    cin >> n >> k >> m >> p;
    ec7 = n * k;
    ec8 = m * p;
    k = ec7;
    p = ec8;
    int r = k % p;
    while (r != 0) {
        k = p;
        p = r;
        r = k % p;
    }
    t = p;
    y = ec7 / t;
    z = ec8 / t;
    x = y + z;
    cout << x << " " << y << " " << z << " " << t;
    return 0;
}
