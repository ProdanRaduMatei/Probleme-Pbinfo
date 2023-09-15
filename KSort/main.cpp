#include <iostream>
#include <algorithm>

using namespace std;

int n, k, v[1001];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v + 1, v + 1 + k);
    sort(v + 1 + k, v + 1 + n);
    for (int i = 1; i <= k; ++i)
        cout << v[i] << " ";
    for (int i = n; i > k; --i)
        cout << v[i] << " ";
    return 0;
}
