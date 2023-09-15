#include <iostream>

using namespace std;

int main()
{
    int n, v[501], m, p;
    bool k = 0;
    cin >> n;
    m = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    p = v[1];
    for (int i = 1; i <= m; ++i)
        if (v[i] != p)
            k = 1;
    for (int i = m + 1; i <= n; ++i)
        if (v[i] != p)
            k = 1;
    if (k == 1)
        cout << "NU";
    else
        cout << "DA";
    return 0;
}
