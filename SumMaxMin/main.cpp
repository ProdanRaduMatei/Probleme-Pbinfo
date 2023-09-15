#include <iostream>

using namespace std;

int main()
{
    int n, m = 1000000, M = 0, i, a, s;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a;
        if (a < m)
            m = a;
        if (a > M)
            M = a;
    }
    s = m + M;
    cout << s;
    return 0;
}
