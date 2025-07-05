#include <iostream>

using namespace std;

int main()
{
    int n, v[1001] = {0}, x, x1, ok;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x < 1000)
            v[x] = 1;
    }
    x = 0;
    x1 = 0;
    ok = 0;
    for (int i = 999; i >= 100 && !ok; --i) {
        if (v[i] == 0 && !x)
            x = i;
        else
            if (v[i] == 0 && x) {
                ok = 1;
                x1 = i;
            }
    }
    if (!x || !x1)
        cout << "NU EXISTA";
    else
        cout << x1 << " " << x;
    return 0;
}
