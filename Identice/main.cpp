#include <iostream>

using namespace std;

int main()
{
    int n, i, j, k, b, c = 0, ok = 1;
    cin >> n;
    int v[n], a[n];
    for (i = 1; i <= n; ++i)
        cin >> v[i];
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i <= n; ++i) {
        b = v[i];
        k = 0;
        c = 0;
        for (j = 1; j <= n; ++j) {
            if (b == a[j])
                ++k;
            if (b == v[j])
                ++c;
        }
        if (c != k)
            ok = 0;
    }
    if (ok)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
