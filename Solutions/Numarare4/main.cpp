#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, v[201], c = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i < n; ++i)
        if (__gcd(v[i], v[n]) == 1)
            ++c;
    cout << c;
    return 0;
}
