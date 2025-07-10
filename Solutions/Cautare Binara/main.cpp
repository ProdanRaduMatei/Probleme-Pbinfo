#include <iostream>

using namespace std;

int main()
{
    int n, m, v[25000], w[200000], s, d, M, g = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    cin >> m;
    for (int j = 1; j <= m; ++j) {
        cin >> w[j];
        s = 1;
        d = n;
        g = 0;
        while (s <= d && g == 0) {
            M = (s + d) / 2;
            if (w[j] == v[M]) {
                g = 1;
                cout << 1 << " ";
            }
            else if (w[j] < v[M])
                d = M - 1;
            else if (w[j] > v[M])
                s = M + 1;
        }
        if (g == 0)
            cout << 0 << " ";
    }
    return 0;
}
