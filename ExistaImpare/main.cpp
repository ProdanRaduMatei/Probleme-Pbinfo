#include <iostream>

using namespace std;

int main()
{
    int n, i, v[100];
    bool ok = 0;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] % 2 > 0)
            ok = 1;
    }
    if (ok == 0)
        cout << "NU";
    else
        cout << "DA";
    return 0;
}
