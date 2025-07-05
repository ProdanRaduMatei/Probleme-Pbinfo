#include <iostream>
#include <cmath>
#include <algorithm>
#define INF 2147000000
using namespace std;
int n,x,y,i,minn=INF,p;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(abs(x-y)<=minn) minn=abs(x-y),p=i;
    }
    cout<<p;
    return 0;
}
