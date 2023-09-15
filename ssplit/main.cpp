#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, st, dr, v[200001], s[200001] = {0}, x, y, z, dif = 10000;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    st = 1;
    dr = n;
    while (st <= dr && ) {
        int m = (st + dr) / 2;
        if (s)
    }
    return 0;
}
