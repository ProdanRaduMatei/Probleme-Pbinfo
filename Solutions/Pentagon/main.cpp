#include <bits/stdc++.h>
using namespace std;
ifstream fin("pentagon.in");
ofstream fout("pentagon.out");
int n , m , a[300][300] , f[300];
int main()
{
    char ch[1000];
    fin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {

        int j = 0;
        fin >> ch;
        while(ch[j] != '\n')
        {
            a[i][j+1]=(int)ch[j]-48;
            j++;
        }
    }
    for(int j = 1 ; j <= m ; j++)
    {
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(a[i][j] == 0) cnt++;
            else f[cnt]++ , cnt = 0;
        }
        if(cnt > 0) f[cnt]++;
    }
    for(int i = 1 ; i <= 200 ; i++)
    {
        if(f[i] > 0) fout << i << ' ' << f[i] << '\n';
    }
}
