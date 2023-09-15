#include <bits/stdc++.h>
using namespace std;
char a[260];
long long int n, s, x = 1, nr;
int main()
{
    cin >> a;
    n = strlen(a);
    for (int i = n - 1; i >= 0 ; i--)
    {
        if (a[i] >= '0' && a[i] <= '9')
            nr = a[i] - '0';
        else
            nr = a[i] - 'A' + 10;
        s += x * nr;
        x = x * 16;
    }
    cout << s;
    return 0;
}
