#include <bits/stdc++.h>

using namespace std;

int n , a[101][101] , b[101][101] , cnt = 1;

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            a[i][j] = cnt , cnt++;

    for(int i = 1 ; i <= n / 4 ; i++)
        for(int j = 1 ; j <= n / 4 ; j++)
            b[i][j] = a[i][j];

    for(int i = n - n / 4 + 1; i <= n ; i++)
        for(int j = 1 ; j <= n / 4 ; j++)
            b[i][j] = a[i][j];

    for(int i = 1 ; i <= n / 4 ; i++)
        for(int j = n - n / 4 + 1; j <= n ; j++)
            b[i][j] = a[i][j];

    for(int i = n - n / 4 + 1 ; i <= n ; i++)
        for(int j = n - n / 4 + 1 ; j <= n ; j++)
            b[i][j] = a[i][j];

    for(int i = n / 4 + 1 ; i <= n - n / 4; i++)
        for(int j = n / 4 + 1 ; j <= n - n / 4; j++)
            b[i][j] = a[i][j];

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
            if(b[i][j] != 0)
                cout << b[i][j] << " ";
            else
                cout << a[n - i + 1][n - j + 1] << " ";
        cout << '\n';
    }
}
