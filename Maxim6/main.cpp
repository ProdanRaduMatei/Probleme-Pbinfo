#include <iostream>

using namespace std;

int main()
{
    int n, v[1001], M = 0, m;
    cin >> n;
    m = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= m; ++i)
        if (v[i] > M)
            M = v[i];
    for (int i = m + 1; i <= n; ++i)
        if (v[i] > M)
            M = v[i];
    cout << M;
    return 0;
}
