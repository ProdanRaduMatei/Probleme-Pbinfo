#include <iostream>

using namespace std;

int main()
{
    int l, c, v[102][102] = {0}, s = 0;
    cin >> l >> c;
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> v[i][j];
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= c; ++j)
        {
            int m = 11;
            if (v[i - 1][j] < m && v[i - 1][j] != 0)
                m = v[i - 1][j];
            if (v[i + 1][j] < m && v[i + 1][j] != 0)
                m = v[i + 1][j];
            if (v[i][j - 1] < m && v[i][j - 1] != 0)
                m = v[i][j - 1];
            if (v[i][j + 1] < m && v[i][j + 1] != 0)
                m = v[i][j + 1];
            if (v[i][j] < m)
            {
                s = s + m - v[i][j];
                v[i][j] = m;
            }
        }
    cout << s;
    return 0;
}
