#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int Inf = 0x3f3f3f3f;
    long long n, M[100001], m[100001], v[100001];
    cin >> n;
    M[0] = -Inf;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] > M[i - 1])
            M[i] = v[i];
        else
            M[i] = M[i - 1];
    }
    m[n + 1] = Inf;
    for (int i = n; i > 0; --i) {
        if (v[i] < m[i + 1])
            m[i] = v[i];
        else
            m[i] = m[i + 1];
    }
    int dif, dif_max = -Inf;
    for (int i = 1; i < n; ++i) {
        dif = M[i] - m[i + 1];
        if (dif > dif_max)
            dif_max = dif;
    }
    cout << dif_max;
    return 0;
}
