#include <iostream>

using namespace std;

int main()
{
    int n, x, mx, p_mx = -1, y;
    cin >> n;
    while (n) {
        cin >> x;
            y = x;
            int p = 0;
            if (x % 2 == 0) {
                ++p;
                while (x % 2 == 0)
                    x = x / 2;
            }
            for (int d = 3; d * d <= x; d = d + 2)
                    if (x % d == 0) {
                        ++p;
                        while(x % d == 0)
                            x = x / d;
                    }
            if (x > 1)
                ++p;
            if (p > p_mx) {
                    p_mx = p;
                    mx = y;
            }
            else if (p == p_mx && y < mx)
                mx = y;
            --n;
    }
    cout << mx;
    return 0;
}
