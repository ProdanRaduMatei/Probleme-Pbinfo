#include <iostream>

using namespace std;

int main()
{
    int n, v[101], m;
    bool k = 1;
    cin >> n;
    m = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= m; ++i)
        if (v[i] % 2 == 1)
            k = 0;
    for (int i = m + 1; i <= n; ++i)
        if (v[i] % 2 == 1)
            k = 0;
    if (k == 0)
        cout << "NU";
    else
        cout << "DA";
    return 0;
}
