#include <iostream>

using namespace std;

int main()
{
    int n, i, v[100], ok = 1;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (i = 1; i < n; ++i) {
        if (v[i] % v[n] != 0)
            ok = 0;
    }
    if (ok == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
