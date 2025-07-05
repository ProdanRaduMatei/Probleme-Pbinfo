#include <iostream>

using namespace std;

int main()
{
    long long n, m;
    int c1[10] = {0}, c2[10] = {0};
    bool ok = 0;
    cin >> n >> m;
    while (n) {
        ++c1[n % 10];
        n = n / 10;
    }
    while (m) {
        ++c2[m % 10];
        m = m / 10;
    }
    for (int i = 0; i <= 9; ++i)
        if (c1[i] > 0 && c2[i] > 0)
            ok = 1;
    if (ok == 0)
        cout << "NU";
    else
        cout << "DA";
    return 0;
}
