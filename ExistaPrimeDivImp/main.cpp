#include <iostream>

using namespace std;

int main()
{
    int n, v[201], m;
    bool k = 0, ok = 0;
    cin >> n;
    m = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= m; ++i) {
        ok = 0;
        if (v[i] % 2 == 0 && v[i] != 2)
            ok = 1;
        else if (v[i] % 2 == 1)
            for (int d = 3; d * d <= v[i]; d = d + 2)
                if (v[i] % d == 0)
                    ok = 1;
        if (ok == 0)
            k = 1;
    }
    for (int i = m + 1; i <= n; ++i) {
        ok = 0;
        if (v[i] % 2 == 0 && v[i] != 2)
            ok = 1;
        else if (v[i] % 2 == 1)
            for (int d = 3; d * d <= v[i]; d = d + 2)
                if (v[i] % d == 0)
                    ok = 1;
        if (ok == 0)
            k = 1;
    }
    if (k == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
