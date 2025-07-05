#include <iostream>

using namespace std;

int main() {
    int n, m, x, y, z, i, ok;
    cin >> n >> m;
    x = 1;
    for (i = 1; i < n; i++)
        x = x * 10;
    y = x * 10;
    for (i = x; i < y; i++) {
        z = i;
        ok = 1;
        while (z) {
            if (z % 10 >= m)
                ok = 0;
        z = z / 10;
        }
        if (ok)
            cout << i << '\n';
    }
    if (m == 1)
        cout << 0;
    return 0;
}
