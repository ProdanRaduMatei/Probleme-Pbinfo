#include <iostream>

using namespace std;

int main()
{
    int n, i, v[200], d, ok = 0, c;
    cin >> n;
    for (i= 1; i <= n; ++i) {
        cin >> v[i];
        c = 0;
        for (d = 2; d * d <= v[i]; ++d)
            if (v[i] % d == 0 && d * d != v[i])
                ++c;
        if (c == 0)
            ok = 1;
    }
    if (ok == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
