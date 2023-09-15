#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101], a, M = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a;
        if (a > M)
            M = a;
    }
    for (int i = 1; i <= n; ++i)
        if (v[i] > M)
            ++cnt;
    cout << cnt;
    return 0;
}
