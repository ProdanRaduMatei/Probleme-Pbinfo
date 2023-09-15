#include <iostream>
using namespace std;
long long v[100001], n, i, j, m, s, k, b, smax;
int main()
{
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> v[i];
    for (i = 2; i <= n; ++i)
        v[i] = v[i] + v[i - 1];
    cin >> m;
    for (k = 1; k <= m; ++k) {
        cin >> i >> j;
        if (i > j)
            swap(i,j);
        s = v[j] - v[i - 1];
        if (s > smax)
            smax = s;
    }
    cout << smax;
}
