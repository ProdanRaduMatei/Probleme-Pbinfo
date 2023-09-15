#include <iostream>

using namespace std;

int main() {
    long long int n;
    cin >> n;
    long long int dmax = 0;
    long long int d = 2;
    while (n > 1) {
        int p = 0;
        while (n % d == 0) {
            n /= d;
            p++;
        }
        if (p != 0)
            dmax = d;
        d++;
        if (d * d > n)
        d=n;
    }
    cout << dmax;
    return 0;
}
