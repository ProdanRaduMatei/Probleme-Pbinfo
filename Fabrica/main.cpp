#include <iostream>

using namespace std;

int main()
{
    int n, k, a[1001], s = 0;
    cin >> n >> k;
    for (int x = 1; x <= n; ++x)
        cin >> a[x];
    for (int x = 1; x <= n; ++x)
        s += (k / a[x]);
    cout << s;
    return 0;
}