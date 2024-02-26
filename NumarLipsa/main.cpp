#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[10001], max = 0, f[10001] = {0}, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
        f[a[i]]++;
    }
    sort(a, a + n);
    for (int i = 1; i <= max; ++i)
    {
        ++cnt;
        if (f[i] == 0)
        {
            cout << i;
            break;
        }
    }
    if (cnt == max)
        cout << a[n - 1] + 1;
    return 0;
}