#include <bits/stdc++.h>
using namespace std;

const int nMAX = 100e3;

int n;
int v[nMAX + 1];
int ks[nMAX + 1];
int ke[nMAX + 1];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    ke[1] = v[1];
    for (int i = 2; i <= n; ++i)
        ke[i] = max(ke[i - 1] + v[i], v[i]);
    for (int i = 2; i <= n; ++i)
        ke[i] = max(ke[i - 1], ke[i]);
    ks[n] = v[n];
    for (int i = n-1; i >= 1; --i)
        ks[i] = max(v[i] + ks[i + 1], v[i]);
    for (int i = n-1; i >= 1; --i)
        ks[i] = max(ks[i], ks[i + 1]);
    int smax = INT_MIN;
    for (int i = 1; i < n; ++i)
        smax = max(smax, ke[i] + ks[i + 1]);
    cout << smax;
}