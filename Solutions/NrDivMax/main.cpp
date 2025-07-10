#include <iostream>

using namespace std;

int main()
{
    int n, i, d, cnt, M = 0, m;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cnt = 0;
        for (d = 1; d * d <= i; ++d) {
            if (d * d == i)
                cnt = cnt + 2;
            else if (i % d == 0)
                cnt = cnt + 2;
        }
        if (cnt > M) {
            M = cnt;
            m = i;
        }
    }
    cout << m;
    return 0;
}
