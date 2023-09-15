#include <iostream>

using namespace std;

int main()
{
    int n, m, v[16][16];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            v[i][j] = i * j;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            for (int j = (i - 1) * m + 1; j <= i * m; ++j)
                cout << j << " ";
            cout << endl;
        }
        else {
            for (int j = i * m; j >= (i - 1) * m + 1; --j)
                cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}
