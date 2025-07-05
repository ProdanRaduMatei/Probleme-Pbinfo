#include <iostream>

using namespace std;

int main()
{
    int n, v[101], m;
    bool k = 0;
    cin >> n;
    m = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= m; ++i)
        if (v[i] % 2 == 1)
            k = 1;
    for (int i = m + 1; i <= n; ++i)
        if (v[i] % 2 == 1)
            k = 1;
    if (k == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
