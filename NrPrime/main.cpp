#include <iostream>

using namespace std;

int main()
{
    int n, m, i, j, cnt = 0, a, d, c = 0;
    cin >> n >> m;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            cin >> a;
            if (i % 2 == 0) {
                if (a != 0 && a != 1) {
                c = 0;
                for (d = 1; d * d <= a; ++d) {
                    if (a % d == 0) {
                        if (d * d == a)
                            ++c;
                        else
                            c = c + 2;
                    }
                }
                if (a == 2)
                    ++cnt;
                if (c == 2)
                    ++cnt;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
