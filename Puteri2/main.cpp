#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int m, p, cif, i, nr;
int exp(int a, int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1) {
        long long tmp = exp(a, n - 1);
        tmp = tmp * a;
        return tmp % nr;
    }
    else {
        long long tmp = exp(a, n / 2);
        return (tmp * tmp) % nr;
    }
}

int main()
{
    cin >> m >> p >> cif;
    nr = 1;
    for (i = 1; i <= cif; ++i)
        nr = nr * 10;
    cout << exp(m, p);
    return 0;
}
