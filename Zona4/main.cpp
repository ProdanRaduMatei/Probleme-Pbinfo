#include <iostream>

using namespace std;

int main()
{
    int n, z, a[201][201], s = 0;
    cin >> n >> z;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    if (z == 1)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i < j && i + j < n + 1)
                    s = s + a[i][j];
    if (z == 2)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i < j && i + j > n + 1)
                    s = s + a[i][j];
    if (z == 3)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i > j && i + j > n + 1)
                    s = s + a[i][j];
    if (z == 4)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i > j && i + j < n + 1)
                    s = s + a[i][j];
    cout << s;
    return 0;
}
