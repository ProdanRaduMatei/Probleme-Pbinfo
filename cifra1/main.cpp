#include <iostream>

using namespace std;

int main()
{
    long long n, m = 0, p = 1, M = 0;
    int c[11], i = 0;
    cin >> n;
    while (n) {
        c[i++] = n % 10;
        n = n / 10;
    }
    for (int j = 0; j < i; ++j) {
        m = 0;
        p = 1;
        for (int a = 0; a < j; ++a) {
            m = m + c[a] * p;
            p = p * 10;
        }
        for (int b = j + 1; b < i; ++b) {
            m = m + c[b] * p;
            p = p * 10;
        }
        if (m > M)
            M = m;
    }
    cout << M;
    return 0;
}
