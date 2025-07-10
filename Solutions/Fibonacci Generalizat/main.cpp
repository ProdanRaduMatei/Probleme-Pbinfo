#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long a,b,c,n;
    cin>>a>>b>>n;
    cout<<a<<" ";
    while(abs(b)<=n)
    {
        cout<<b<<" ";
        c=a+b;
        a=b;
        b=c;
    }
    return 0;
}
