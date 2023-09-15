#include <bits/stdc++.h>

using namespace std;

bool prim(int x) {
    if (x < 2)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int i = 3; i * i <= x; i = i + 2)
        if (x % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n, m, v[601][601], c = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            if (j % 2 == 1 && prim(v[i][j]) == 1)
                ++c;
        }
    cout << c;
    return 0;
}
