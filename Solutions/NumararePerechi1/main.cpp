#include <bits/stdc++.h>

using namespace std;

int n, i, c, j, v[1001], sum;

int main() {
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if ((v[i] / 10) % 10 == (v[j] / 10) % 10)
                sum++;
    cout << sum;
    return 0;
}