#include <iostream>

using namespace std;

int main() {
    long long n, ok = 1, u;
    cin >> n;
    if (n < 10)
    {
        cout << "da";
        return 0;
    }
    u = (n % 10) % 2;
    while (n > 9 && ok)
    {
        n = n / 10;
        if (u == (n % 10) % 2)
            ok = 0;
        u = (n % 10) % 2;
    }
    if (n != 0)
        if (n % 2 != u)
            ok = 0;
    if (ok)
        cout << "da";
    else
        cout << "nu";
    return 0;
}
