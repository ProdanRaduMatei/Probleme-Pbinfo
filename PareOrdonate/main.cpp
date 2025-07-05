#include <iostream>

using namespace std;

int main()
{
    int n, i, v[100], ok = 1, m = -1;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] % 2 == 0) {
            if (v[i] < m && m != -1)
                ok = 0;
            m = v[i];
        }
    }
    if (ok == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
