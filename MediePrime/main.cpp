#include <iostream>

using namespace std;

int main()
{
    int n, i, a, c = 0, cnt, d;
    float m = 0;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a;
        cnt = 0;
        if (a != 1) {
            for (d = 2; d * d <= a; ++a) {
                if (a % d == 0) {
                    if (d * d == a)
                        ++cnt;
                    else if (a % d == 0)
                        cnt = cnt + 2;
                }
            }
            if (cnt == 0) {
                m = m + a;
                ++c;
            }
        }
    }
    m = m / c / 100;
    cout << m;
    return 0;
}
