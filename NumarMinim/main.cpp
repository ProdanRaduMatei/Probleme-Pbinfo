#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<1;
    for(int i=1;i<n-1;++i)
        cout<<0;
    if(k)
        cout<<k-1;
    else
        cout<<8;
    return 0;
}
