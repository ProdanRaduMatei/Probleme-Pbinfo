#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

int n, k, v[5000005];

struct sir{
    long long a, b, c, d;
}el;

int main()
{
    cin >> n >> k;
    cin >> el.a >> el.b >> el.c >> el.d;
    v[1] = el.a;
    for (int i = 2; i <= n; ++i)
        v[i] = (el.b * v[i - 1] + el.c) % el.d;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (v[i] < v[j])
                swap(v[i], v[j]);
    for (int i = k; i >= 1; --i)
        cout << v[i] << " ";
    return 0;
}
