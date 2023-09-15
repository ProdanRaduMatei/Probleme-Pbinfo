#include <iostream>

using namespace std;

int main()
{
    int v[101][101], n, m, c = 0, e;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        cin >> v[i][j];
    if (n == 1)
        c = 0;
    else {
        for (int i = 2; i <= n; ++i) {
            e = 1;
            for (int j = 1; j <= m && e; ++j)
                if (v[i][j] != v[i - 1][j])
                    e = 0;
            if (e)
                ++c;
        }
    }
    cout << c;
    return 0;
}
