#include <iostream>

using namespace std;

int main()
{
    int n, q, p, x, cp = 0, cq = 0, cx;
    cin >> p >> q >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        cx = x;
        while (x % p == 0) {
            x = x / p;
            ++cp;
        }
        while (cx % q == 0) {
            cx = cx / q;
            ++cq;
        }
    }
    cout << min(cp, cq);
    return 0;
}
