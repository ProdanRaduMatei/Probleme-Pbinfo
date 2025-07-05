#include <iostream>

using namespace std;

int mod(int x) {
    if (x < 0)
        return -1 * x;
    return x;
}

int main()
{
    long long n, c;
    int a, b = 0, nrc = 0, p = 1;
    cin >> n;
    c = n;
    while (c) {
        c = c / 10;
        ++nrc;
    }
    for (int i = 1; i <= nrc / 2; ++i) {
        b = b + n % 10 * p;
        p = p * 10;
        n = n / 10;
    }
    if (nrc % 2 == 1)
        a = n / 10;
    else
        a = n;
    cout << mod(a - b);
    return 0;
}
