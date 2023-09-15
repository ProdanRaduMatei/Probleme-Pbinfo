#include <iostream>

using namespace std;

int main()
{
    int n, m, v[51], x, s = 0, sm = 0, l;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        s = 0;
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            s = s + x * v[j];
        }
        if (s > sm) {
            sm = s;
            l = i;
        }
    }
    cout << l;
    return 0;
}
