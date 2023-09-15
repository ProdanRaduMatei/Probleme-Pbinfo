#include <bits/stdc++.h>
using namespace std;

ifstream fin("asfalt.in");
ofstream fout("asfalt.out");

int main()
{
    int n , m;
    fin >> n >> m;
    int f[10001]={0};
    int a , b;
    int x=0 , y=0;
    for(int i = 0 ; i < m ; ++i)
    {
        fin >> a >> b;
        for(int j = a ; j < b ; ++j)
            f[j]++;
    }
    for(int i = 0 ; i < n ; ++i)
    {
        if(f[i]==0)
            x++;
        if(f[i]>1)
            y++;
    }
    fout << x << ' ' << y;
}
