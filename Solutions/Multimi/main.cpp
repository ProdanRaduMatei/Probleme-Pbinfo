#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, p = 0, a[1001], b[1001], u[2002], r[1001];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        u[i] = a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        u[n + i] = b[i];
    }
    sort(u, u + n + m);
    int s = n + m;
    for (int i = 0; i < s; ++i)
        if (u[i - 1] != u[i])
            cout << u[i] << " ";
    cout << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i] == b[j])
                r[p++] = a[i];
    sort(r, r + p);
    for (int i = 0; i < p; ++i)
        if (r[i - 1] != r[i])
            cout << r[i] << " ";
    return 0;
}