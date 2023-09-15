#include <iostream>


using namespace std;
int main()
{
    int z,l,a,p,ok;
    cin>>z>>l>>a;
    ok=0;
    p=0;
    if (z>0 && z<=31)
        ok=1;
    else
        p=1;
    if(l>=1 && l<=12)
    ok=1;
    else
        p=1;
    if(a>=1850 && a<=2500)
        ok=1;
    else
        p=1;
    if(ok == 1 && p == 0)
        cout<<"DA";
    else
        cout<<"NU";
    return 0;
}
