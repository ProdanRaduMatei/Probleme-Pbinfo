#include <iostream>

using namespace std;
int n,t,k,a,c=0;
int main()
{
    cin>>n>>t>>k;
    int nr=0;
    for(int i=0;i<n;i++)
    {

        cin>>a;
        if(a<=t)
            nr++;
        else
            nr=0;
        if(nr>=k)
            c++;
    }
    cout<<c;
    return 0;
}
