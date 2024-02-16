#include <iostream>
#include <algorithm>

using namespace std;

int cmmdc(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, a[3001];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int maxim = a[2] - a[1];
    for (int i = 2; i < n; ++i)
        maxim = cmmdc(maxim, a[i + 1] - a[i]);
    if (maxim > 1)
        cout << "DA";
    else
        cout << "NU";
}