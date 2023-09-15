#include <iostream>

using namespace std;

int main()
{
    long long n, c, s = 0, cn = 0, p = 1;
    cin >> n;
    c = n;
    s = n;
    while (c) {
        p = p * 10;
        ++cn;
        c = c / 10;
    }
    p = p / 10;
    for (int i = 1; i < cn; ++i) {
        n = (n % 10) * p + n / 10;
        s = s + n;
    }
    cout << s;
    return 0;
}
