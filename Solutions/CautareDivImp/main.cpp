#include <iostream>

using namespace std;

int main()
{
    int n, m, x[1001], y[1001], j;
    bool k = 1;
    cin >> n;
    j = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> y[i];
    for (int a = 1; a <= m; ++a) {
        k = 0;
        for (int b = 1; b <= j; ++b)
            if (x[b] == y[a])
                k = 1;
        if (k == 0)
            for (int b = j + 1; b <= n; ++b)
                if (x[b] == y[a])
                    k = 1;
        cout << k << " ";
    }
    return 0;
}
