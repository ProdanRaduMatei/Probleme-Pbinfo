#include <iostream>

using namespace std;

int main()
{
    int n, i, ok = 1, v[100];
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] % 2 != 0)
            ok = 0;
    }
    if (ok == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
