#include <iostream>

using namespace std;

void duplicare(int n, int &d) {
    int u, p = 1, m = n;
    d = 0;
    while (m) {
        u = m % 10;
        if (u % 2 == 0) {
            d = d + u * p + u * p * 10;
            p = p * 100;
        }
        else {
            d = d + u * p;
            p = p * 10;
        }
        m = m / 10;
    }
    if (n == d)
        d = -1;
}

int main()
{
    int n, d;
    cin >> n;
    duplicare(n, d);
    cout << d;
    return 0;
}
