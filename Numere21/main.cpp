#include <iostream>
#include <algorithm>

using namespace std;

long long ogl(long long x) {
    long long o = 0;
    while (x) {
        o = o * 10 + x % 10;
        x = x / 10;
    }
    return o;
}

int main()
{
    long long a, b, c, d, s = 0;
    do {
        cin >> a >> b;
        c = ogl(a);
        d = ogl(b);
        if (__gcd(a, b) == 1 && __gcd(c, d) == 1)
            s = s + a + b;
    } while (a != 0 && b != 0);
    cout << s;
    return 0;
}
