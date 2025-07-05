#include <iostream>
using namespace std;
int main()
{
    int a[25][25];
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)

        if(i==j)
            a[i][j]=0;
        else
            if(i+j==n+1)
                a[i][j]=0;
            else
                if((i<j)&&(i+j<=n))
                    a[i][j]=1;
                else
                    if((i>j)&&(i+j>n))
                            a[i][j]=2;
                    else
                    a[i][j]=3;
       for(i=1;i<=n;i++)
           {for(j=1;j<=n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
            }
}
