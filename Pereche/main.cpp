#include <iostream>
using namespace std;

int main()
{
    int a[1002];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    a[n] = a[0];
    n++;
    int st = 0, dr = 0, min = 1001;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i - 1])
        {
            if (a[i] - a[i - 1] < min)
            {
                min = a[i] - a[i - 1];
                st = i - 1;
                dr = i;
            }
        }
        else
        {
            if (a[i - 1] - a[i] < min)
            {
                min = a[i - 1] - a[i];
                st = i - 1;
                dr = i;
            }
        }
    }
    if (dr == n - 1)
    {
        st = 0;
        dr = n - 2;
    }
    cout << st + 1 << ' ' << dr + 1;
    return 0;
}