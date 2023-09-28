#include <bits/stdc++.h>
using namespace std;
int n, v[2005], minim = 1500000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        minim = min(minim, v[i]);
    }
    for (int i = 1; i <= n; ++i)
        if (v[i] == minim)
            cout << v[i] << ' ' << v[i] << ' ';
        else
            cout << v[i] << ' ';
    return 0;
}