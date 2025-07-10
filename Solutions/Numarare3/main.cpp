#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, v[201], cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n / 2; ++i) {
        if (__gcd(v[i], v[n - i + 1]) == 1)
            ++cnt;
    }
    cout << cnt;
    return 0;
}
