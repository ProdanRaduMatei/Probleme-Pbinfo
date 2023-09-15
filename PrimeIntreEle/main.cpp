#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, j, cnt = 0, a = 1;
    cin >> n;
    for (i = 1; i < n; ++i) {
        for (j = a; j <= n; ++j) {
            if (__gcd(i, j) == 1) {
                ++cnt;
            }
        }
        ++a;
    }
    cout << cnt;
    return 0;
}
