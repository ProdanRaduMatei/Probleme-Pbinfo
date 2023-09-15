#include<bits/stdc++.h>
using namespace std;
ifstream fin("spirala1.in");
ofstream fout("spirala1.out");
int main()
{
    int a[101][101],n,i,j,k,x;
    fin>>n;
    n=sqrt(n);
    for(k=1;k<=(n+1)/2;k++)
    {
        for(i=k;i<=n+1-k;i++)
            fin>>a[i][k];
        for(j=k+1;j<=n+1-k;j++)
            fin>>a[n+1-k][j];
        for(i=n-k;i>=k;i--)
            fin>>a[i][n+1-k];
        for(j=n-k;j>k;j--)
            fin>>a[k][j];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            fout<<a[i][j]<<" ";
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
