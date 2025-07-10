#include <iostream>
#define INF 2147000000
using namespace std;
int w[10],n,x,i,j,cif,p,minn=INF;
bool ok;
int main()
{
cin>>n;
for(i=1;i<=n;i++)
{
cin>>x;
while(x)
{
cif=x%10;
x=x/10;
w[cif]=w[cif]+1;
}
}
do
{
ok=true;
minn=INF;
for(i=0;i<=9;i++)
if((w[i]<minn)&&(w[i]))
    minn=w[i], p=i, ok=false;
w[p]=INF;
if(!ok) cout<<p<<" ";
} while(!ok);
return 0;
}
