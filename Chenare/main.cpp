#include <iostream>
using namespace std;
int a[55][55], i, j, n;
int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        for(j = 1;j <= n; j++)
            if(i + j <= n + 1)
                if(i > j)
                    a[i][j] = j;
                else
                    a[i][j] = i;
            else {
                if(n - i > n - j)
                    a[i][j] = n - j + 1;
                else
                    a[i][j] = n - i + 1;
            }
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
