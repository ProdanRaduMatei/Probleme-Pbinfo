#include <iostream>

using namespace std;

int main()
{
    int n, v[1000], i, m = 0, cnt;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] > m) {
            m = v[i];
            cnt = 0;
        }
        if (v[i] == m)
            ++cnt;
    }
    cout << m << " " << cnt;
    return 0;
}
