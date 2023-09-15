#include <iostream>

using namespace std;

void duplicare(int &n) {
    int u, p = 1, m = n, d = 0, i;
    while (m) {
        u = m % 10;
        if (u % 2 == 0) {
            i = u / 2;
            d = d + i * p + u * p * 10;
            p = p * 100;
        }
        else {
            d = d + u * p;
            p = p * 10;
        }
        m = m / 10;
    }
    n = d;
}

int main()
{
    int n;
    cin >> n;
    duplicare(n);
    cout << n;
    return 0;
}
