#include <bits/stdc++.h>

using namespace std;

int n, i, c, j, v[1001], sum;

int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (i = 1; i <= n / 2; i++)
        if ((v[i] / 10) % 10 == (v[(n + 1) - i] / 10) % 10)
            sum++;
    cout << sum;
    return 0;
}