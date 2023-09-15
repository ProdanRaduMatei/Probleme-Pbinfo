#include <iostream>

using namespace std;

int main()
{
    int n, v[101], m, cn = 0, c;
    bool k = 1;
    cin >> n;
    m = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= m; ++i) {
        cn = 0;
        c = v[i];
        while (c) {
            ++cn;
            c = c / 10;
        }
        if (cn % 2 == 1)
            k = 0;
    }
    for (int i = m + 1; i <= n; ++i) {
        cn = 0;
        c = v[i];
        while (c) {
            ++cn;
            c = c / 10;
        }
        if (cn % 2 == 1)
            k = 0;
    }
    if (k == 0)
        cout << "NU";
    else
        cout << "DA";
    return 0;
}
