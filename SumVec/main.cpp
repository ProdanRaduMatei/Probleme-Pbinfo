#include <iostream>

using namespace std;

int main()
{
    int n, v[1001], s1 = 0, s2 = 0, s = 0, m;
    cin >> n;
    m = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= m; ++i)
        s1 = s1 + v[i];
    for (int i = m + 1; i <= n; ++i)
        s2 = s2 + v[i];
    s = s1 + s2;
    cout << s;
    return 0;
}
