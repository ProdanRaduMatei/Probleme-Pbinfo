#include <iostream>

using namespace std;

int main()
{
    int n, i, v[500], ok = 1;
    cin >> n >> v[1];
    for (i = 2; i <= n; ++i) {
        cin >> v[i];
        if (v[i] != v[i - 1])
            ok = 0;
    }
    if (ok == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
