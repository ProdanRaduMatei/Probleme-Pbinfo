#include <iostream>

using namespace std;

int main()
{
    int n, s = 0, u, x, m = 0, p = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        u = x % 10;
        m = 0;
        p = 1;
        while (x) {
            if (x % 10 != u) {
                m = m + x % 10 * p;
                p = p * 10;
            }
            x = x / 10;
        }
        s = s + m;
    }
    cout << s;
    return 0;
}
