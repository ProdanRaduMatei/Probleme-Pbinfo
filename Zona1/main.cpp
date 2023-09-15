#include <iostream>
using namespace std;
int v[1000];
int main()
{
    int n,maxx=0;
    unsigned int a[200][200];
    cin>>n;
    for(int i =1 ;i<=n;i++)
        for(int j=1; j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if((i>j)&&(j>n-i+1))
            {
                v[a[i][j]]++;
                if(a[i][j]>maxx)
                    maxx=a[i][j];
            }
        }
    for(int i=1;i<=maxx;i++)
    {
        if(v[i]>=2)
            cout<<i << " ";
    }
    return 0;
}
