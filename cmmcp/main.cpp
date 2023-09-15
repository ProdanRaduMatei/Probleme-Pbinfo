#include <iostream>

using namespace std;

int main()
{
    long long n, c = -1;
    cin >> n;
    if (n == 0)
        c = 0;
    while (n) {
        int u = n % 10;
        if (u % 2 == 0 && u > c)
            c = u;
        n = n / 10;
    }
    if (c == -1)
        cout << 10;
    else
        cout << c;
    return 0;
}
