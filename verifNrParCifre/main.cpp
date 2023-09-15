#include <iostream>

using namespace std;

int main()
{
    int n, i, v[100], ok = 1, cnt;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> v[i];
        cnt = 0;
        while (v[i] > 0) {
            v[i] = v[i] / 10;
            ++cnt;
        }
        if (cnt % 2 != 0)
            ok = 0;
    }
    if (ok == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
