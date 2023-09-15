#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, v[100001], s = 0, S[100001], m = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    if (n == 1) {
        cout << v[1];
        return 0;
    }
    if (n == 2) {
        cout << v[1] + v[2];
        return 0;
    }
    sort(v + 1, v + 1 + n);
    S[m++] = v[1] + v[2];
    for (int i = 3; i <= n; ++i) {
        S[m] = S[m - 1] + v[i];
        ++m;
    }
    for (int i = 1; i < m; ++i)
        s = s + S[i];
    cout << s;
    return 0;
}
