#include <iostream>

using namespace std;

int main()
{
    int n, m, M = 0, cn = 0, MM = 0, x;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> x;
            if (x > M)
                M = x;
        }
        if (M == MM)
            ++cn;
        else if (M > MM) {
            MM = M;
            cn = 1;
        }
    }
    cout << MM << " " << cn;
    return 0;
}
