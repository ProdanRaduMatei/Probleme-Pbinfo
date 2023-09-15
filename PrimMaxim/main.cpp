#include <iostream>

using namespace std;

int main()
{
    int n, i, a, m = 0, d, c, cnt;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a;
        cnt = 0;
        for (d = 2; d * d <= a; ++d) {
            if (a % d == 0 && a != 1) {
                if (d * d == a)
                    ++cnt;
                else if (a % d == 0)
                    cnt = cnt + 2;
            }
        }
        if (cnt == 0 && a != 0) {
            if (a > m) {
                m = a;
                c = 0;
            }
            if (a == m)
                ++c;
        }
    }
    cout << m << " " << c;
    return 0;
}
