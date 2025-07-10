#include <iostream>
using namespace std;

int main()
{
    unsigned long long n,d=2;
    cin>>n;
    unsigned long long nr=n;
    while(n!=1)
    {
        if(n%d==0)
        {
            nr/=d;
            nr*=d-1;
            while(n%d==0)
                n/=d;
        }
        if(d==2)
            d=3;
        else
            d+=2;
        if(d*d>n)
            d=n;
    }
    cout<<nr;
    return 0;
}
