#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int f[101];

int main()
{
    int n, nr;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nr;
        ++f[nr];
    }
    int sosete = 0;
    for (int i = 1; i <= 101; ++i)
        sosete = sosete + f[i] / 2;
    cout << sosete;
    return 0;
}
