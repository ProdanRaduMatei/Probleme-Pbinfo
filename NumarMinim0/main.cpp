#include <iostream>

using namespace std;

int n, i, m[11], b, r, cif, num[11], r2, j;

int main()
{
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> m[i] >> b >> r;
        r2 = 1;
        for (j = 1; j < m[i]; ++j)
            r2 = (r2 * 10) % b;
        if (r >= 2)
            cif = r - r2;
        else
            cif = b + r - r2;
        num[i] = cif;
    }
    for (i = 1; i <= n; ++i) {
        cout << 1;
        for (j = 1; j <= m[i] - 2; ++j)
            cout << 0;
        cout << num[i] << endl;
    }
    return 0;
}
