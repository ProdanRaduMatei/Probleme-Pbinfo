#include <iostream>

using namespace std;

int main()
{
    int n, m, v[251][251], c = 0, s = 0, ii, jj;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> v[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i][j] == 1)
                if (v[i - 1][j] == 0 && v[i][j - 1] == 0) {
                    ++c;
                    ii = i;
                    jj = j;
                    while (v[i][jj] == 1)
                        ++jj;
                    while (v[ii][j] == 1)
                        ++ii;
                    if (s < (ii - i)*(jj - j))
                        s = (ii - i) * (jj - j);
                }
    cout << c << " " << s;
    return 0;
}
