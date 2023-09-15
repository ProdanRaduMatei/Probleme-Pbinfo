#include <bits/stdc++.h>
using namespace std;
bool a[102][102] , b[102][102];
int main()
{
    int n , m , cnt = -1 , ok = 0;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
    {
        a[i][0]=1;
        a[i][m+1]=1;
    }
    for(int i = 1 ; i <= m ; ++i)
    {
        a[0][i]=1;
        a[n+1][i]=1;
    }
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
        {
            cin >> a[i][j];
            b[i][j]=a[i][j];
        }
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            if(a[i][j]==1) ok = 1;
    while(ok == 1)
    {
        ok = 0;
        cnt++;
        for(int i = 1 ; i <= n ; ++i)
            for(int j = 1 ; j <= m ; ++j)
                if((a[i+1][j]==0 && a[i][j+1]==0)||(a[i+1][j]==0 && a[i-1][j]==0)||(a[i+1][j]==0 && a[i][j-1]==0)||(a[i][j+1]==0 && a[i-1][j]==0)||(a[i][j+1]==0 && a[i][j-1]==0)||(a[i-1][j]==0 && a[i][j-1]==0))
                    b[i][j]=0;
        for(int i = 1 ; i <= n ; ++i)
            for(int j = 1 ; j <= m ; ++j)
                if(b[i][j]!=a[i][j]) ok = 1;
        for(int i = 1 ; i <= n ; ++i)
            for(int j = 1 ; j <= m ; ++j)
                a[i][j]=b[i][j];
    }
    ok = 0;
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            if(a[i][j]==1) ok=1;
    if(ok==0) cout << cnt;
    else cout << -1;
    return 0;
}
