#include <iostream>
using namespace std;
int n,a[1001][1001];
int main(){
    cin>>n;
    int jn;
    if(n%2)
        jn=n/2+1;
    else
        jn=n/2;
    int t=1;
    for(int k=1;k<=jn;k++){
        for(int i=k;i<=n-k+1;i++)
            a[k][i]=t;
    for(int i=k;i<=n-k+1;i++)
        a[n-k+1][i]=t;
    for(int i=k+1;i<=n-k;i++)
        a[i][k]=t;
    for(int i=k+1;i<=n-k;i++)
        a[i][n-k+1]=t;
    if(t)
        t=0;
    else
        t=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
