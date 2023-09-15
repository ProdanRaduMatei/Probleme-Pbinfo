#include <iostream>

using namespace std;

int mod(int a, int b) {
    if (a - b < 0)
        return -1 * (a - b);
    return (a - b);
}

int main()
{
    long long n, n1 = 0, n2 = 0, p1 = 1, p2 = 1;
    int u;
    cin >> n;
    while (n) {
        u = n % 10;
        if (u % 2 == 0) {
            n1 = n1 + p1 * u;
            p1 = p1 * 10;
        }
        else {
            n2 = n2 + p2 * u;
            p2 = p2 * 10;
        }
        n = n / 10;
    }
    cout << mod(n1, n2);
    return 0;
}
