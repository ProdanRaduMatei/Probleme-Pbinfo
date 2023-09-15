#include <iostream>

using namespace std;

int main()
{
    int n, i, a, m = 100000, M = 0, d, cnt, c = 0;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a;
        cnt = 0;
        for (d = 2; d * d <= a; ++d) {
            if (a % d == 0) {
                if (d * d == a)
                    ++cnt;
                else if (a % d == 0)
                    cnt = cnt + 2;
            }
        }
        if (cnt == 0) {
            if (a < m && a != 1)
                m = a;
            if (a > M)
                M = a;
            if (a != 1)
                ++c;
        }
    }
    cout << c << " " << m << " " << M;
    return 0;
}
