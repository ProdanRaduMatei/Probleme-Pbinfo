#include <iostream>

using namespace std;

int main()
{
    long long n, num, m, exp2 = 0, exp5 = 0, u = 1, cif;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        while (num % 2 == 0) {
            num = num / 2;
            ++exp2;
        }
        while (num % 5 == 0) {
            num = num / 5;
            ++exp5;
        }
        cif = num / 10;
        u = (u * cif) % 10;
    }
    if (exp2 > exp5) {
        exp2 = exp2 - exp5;
        m = exp2 % 4;
        if (m == 1)
            u = (u * 2) % 10;
        if (m == 2)
            u = (u * 4) % 10;
        if (m == 3)
            u = (u * 8) % 10;
        if (m == 0)
            u = (u * 6) % 10;
    }
    else
        if (exp2 == exp5)
            u = u;
        else
            u = 5;
    cout << u;
    return 0;
}
