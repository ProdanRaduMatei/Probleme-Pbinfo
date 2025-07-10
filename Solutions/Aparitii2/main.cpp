#include <iostream>

using namespace std;

int n, p, c, m, cnt;
int main()
{
    cin >> n;
    m = n;
    while (m) {
        p = m % 10;
        m = m / 10;
    }
    while (n) {
        c = n % 10;
        if (c == p)
            ++cnt;
        n = n / 10;
    }
    cout << cnt;
    return 0;
}
