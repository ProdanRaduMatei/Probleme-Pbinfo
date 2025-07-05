#include <iostream>

using namespace std;

long long desc(long long n){
    long long prod = 1;
    long long d = 2;
    while (n > 1) {
        int p = 0;
        while (n % d == 0) {
            n /= d;
            p++;
        }
        if (p)
            prod *= d;
        d++;
        if (d * d > n)
            d = n;
    }
    return prod;
}
int main() {
    long long a, b;
    cin >> a >> b;
    long long prod1 = desc(a);
    long long prod2 = desc(b);
    if (prod1 > prod2)
        cout << a;
    else if (prod1 == prod2)
        cout << min(a, b);
    else
        cout << b;
}
