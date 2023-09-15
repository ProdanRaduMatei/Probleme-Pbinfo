#include <iostream>
using namespace std;
int main()
{
    int n,a,MAX=-1000000000;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        if(a>MAX)
            MAX=a;
    }
    cout<<MAX;
    return 0;
}
