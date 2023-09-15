#include <iostream>

using namespace std;

int main()
{
    unsigned long long int n, m, x, y, c1 = 0, c2 = 0, c3 = 0, c4 = 0, M = 0;
    cin >> x >> y >> n >> m;
    if (n == m) {
        c1 = x + y - 1;
        c2 = x + n - y;
        c3 = n - y + m - x + 1;
        c4 = y + m - x;
    }
    else {
        if (m == 1) {
            c1 = x + y - 1;
            c2 = x + n - y;
        }
        if (n == 1) {
            c1 = x + y - 1;
            c2 = n - x + 1;
        }
        else {
            c1 = x + y - 1;
            c2 = x + n - y + 1;
            c3 = n - y + m - x + 1;
            c4 = y + m - x - 1;
        }
    }
    if (c1 > M)
        M = c1;
    if (c2 > M)
        M = c2;
    if (c3 > M)
        M = c3;
    if (c4 > M)
        M = c4;
    cout << M;
    return 0;
}
