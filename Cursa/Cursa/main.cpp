#include <iostream>

using namespace std;

int prim(int x)
{
    if (x < 2)
        return 0;
    if (x > 2 && x % 2 == 0)
        return 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int perfect(int x)
{
    int s = 0;
    while (x)
    {
        s += x % 10;
        x /= 10;
    }
    if (prim(s))
        return 1;
    return 0;
}

int main() {
    int n, m, a[501][501], cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (prim(a[i][j]))
            {
                cnt += 2;
                a[i][j] = 1;
                if (i - 1 > 0)
                    --i;
                if (j - 1 > 0)
                    --j;
            }
            else if (perfect(a[i][j]))
            {
                cnt += 2;
                a[i][j] = 1;
                if (i + 1 <= n)
                    ++i;
                if (j + 1 <= m)
                    ++j;
            }
            else
                ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
