#include <iostream>

using namespace std;

int main() {
    long long int n;
    cin >> n;
    long long int cnt = 1, d = 2;
    long long int cn = n;
    while (n > 1) {
        int p = 0;
        while (n % d == 0) {
            n /= d;
            p++;
        }
        cnt *= (p * cn + 1);
        d++;
        if (d * d > n)
            d = n;
        while (cnt >= 59999)
            cnt %= 59999;
    }
    cout << cnt % 59999;
    return 0;
}
