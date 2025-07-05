#include <iostream>
using namespace std;
int main()
{
    int n,a[21][21],i,j;
    long int S=0,K=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<"a["<<i<<"]["<<j<<"]=";
            cin>>a[i][j];
        }
    }
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            S+=a[i][j];
            K+=a[j][i];
        }
    int r=S%K;
    while(r)
    {
        S=K;
        K=r;
        r=S%K;
    }
    cout<<K;
    return 0;
}
