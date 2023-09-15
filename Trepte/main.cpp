#include <bits/stdc++.h>

using namespace std;

int v[35], n, i;

int main()
{
    cin >> n;
    v[1] = 1;
    v[2] = 2;
    for (i = 3; i <= n; ++i)
        v[i] = v[i - 1] + v[i - 2];
    cout << v[n];
    return 0;
}
