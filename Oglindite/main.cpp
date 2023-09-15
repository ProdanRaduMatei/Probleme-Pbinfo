#include <iostream>

using namespace std;

int mod(int x) {
    if (x < 0)
        return -1 * x;
    return x;
}

int main()
{
    int n, x, c, o, m = 1000000000, a;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        c = x;
        o = 0;
        while (x) {
            o = o * 10 + x % 10;
            x = x / 10;
        }
        if (m == mod(c - o) && c < a)
            a = c;
        if (m > mod(c - o)) {
            m = mod(c - o);
            a = c;
        }
    }
    cout << a;
}
