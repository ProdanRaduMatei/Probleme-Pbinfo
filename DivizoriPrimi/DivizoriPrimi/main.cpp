#include <iostream>

using namespace std;

int prim(long long n) {
    long long d = 2;
    long long p;
    while (n > 1) {
        p = 0;
        while (n % d == 0) {
            p++;
            n /= d;
        }
        if (p > 0)
            return d;
        d++;
        if (d * d > n)
            d = n;
    }
}

int main() {
   long long n, x, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
            cin >> x;
            s = s + prim(x);
        }
    cout << s;
    return 0;
}
