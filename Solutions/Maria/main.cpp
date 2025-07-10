#include <bits/stdc++.h>
using namespace std;

ifstream fin("maria.in");
ofstream fout("maria.out");

int n , m , p , q , a[1001][1001] , k , x , y , s[1001][1001] , cnt;

bool inside(int i , int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

int main()
{
    fin >> n >> m >> p >> q >> k;
    for(int i = 1 ; i <= k ; i++)
    {
        fin >> x >> y;
        a[x][y] = 1;
    }

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            int inou = i + p - 1 , jnou = j + q - 1;
            if(inside(inou , jnou) && s[inou][jnou] - s[i - 1][jnou] - s[inou][j - 1] + s[i - 1][j - 1] == 0)
                cnt++;
            inou = i + q - 1 , jnou = j + p - 1;
            if(inside(inou , jnou) && s[inou][jnou] - s[i - 1][jnou] - s[inou][j - 1] + s[i - 1][j - 1] == 0)
                cnt++;
        }
    }
    fout << cnt;
}
