#include <iostream>

using namespace std;

int main()
{
    int n, m, x[1000], y[1000], k;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> y[i];
    for (int j = 1; j <= m; ++j) {
        k = 0;
        for (int i = 1; i <= n; ++i) {
            if (y[j] == x[i])
                ++k;
        }
        if (k >= 1)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    return 0;
}
