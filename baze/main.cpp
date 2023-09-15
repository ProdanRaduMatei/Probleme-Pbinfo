#include <iostream>
using namespace std;
int n,m,p,r,b,c,x[100],k;

int main()
{
    cin>>n>>b>>c;
    //conversia lui n din baza b in baza 10 si se obtine m
    p=1;
    while(n!=0)
    {
        r=n%10;
        m=m+r*p;
        p=p*b;
        n=n/10;
    }
    //conversia lui m din baza 10 in baza c si se obtine n
    p=1;
    while(m!=0)
    {
        r=m%c;
        k++;
        x[k]=r;
        m=m/c;
    }
    for(int i=k;i>=1;i--)
        cout<<x[i];
    return 0;
}
