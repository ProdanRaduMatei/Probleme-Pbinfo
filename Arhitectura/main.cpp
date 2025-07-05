#include <iostream>
#include <algorithm>

using namespace std;

int n, v[1001];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v + 1, v + 1 + n);
    for (int i = n; i >= 1; --i)
        cout << v[i] << " ";
    return 0;
}
