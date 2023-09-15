#include <iostream>

using namespace std;

unsigned long long int n,x[1001],m,y[1001],i,j,c;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>x[i];
    cin>>m;
    for(j=1;j<=m;j++)
        cin>>y[j];
    int ok;
    for(i=1;i<=n;i++)
        if(x[i]==y[1])
        {
            ok=1;
            for(j=2;j<=m&&(i+j-1)<=n;j++)
                if(x[i+j-1]!=y[j])
                {
                    ok=0;
                    break;
                }
            if(ok&&(j-1)==m)
                c++;
        }
    cout<<c;
    return 0;
}
