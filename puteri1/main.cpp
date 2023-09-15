#include <bits/stdc++.h>

using namespace std;

int n, k, x, nr;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        int c = 1;
        while (x != 0) {
            if (x % k > 1) {
                c = 0;
                break;
            }
            x = x / k;
        }
        if (c)
            ++nr;
    }
    cout << nr;
    return 0;
}
