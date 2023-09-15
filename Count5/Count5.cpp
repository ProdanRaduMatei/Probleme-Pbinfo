#include <iostream>
using namespace std;
int n, i, j, v[205], x, y, s1, s2, ct;
int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
        {
            s1 = 0;
            x = v[i];
            while (x != 0)
            {
                s1 = s1 + x % 10;
                x = x / 10;
            }
            s2 = 0;
            y = v[j];
            while (y != 0)
            {
                s2 = s2 + y % 10;
                y = y / 10;
            }
            if (s1 == s2) ct++;
        }
    cout << ct;
    return 0;
}