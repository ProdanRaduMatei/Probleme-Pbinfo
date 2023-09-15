#include <iostream>
using namespace std;
int main()
{
    long long int n,i,a,unu=1,lung=0,lm=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        unu=1;
        if(a==1||a==3||a==7||a==15||a==31||a==63||a==127||a==255||a==511||a==1023||a==2047||a==4095||a==8191||a==16383||a==32767||a==65535||a==131071||a==262143||a==524287)
            unu=1;
        else
            unu=0;
        if(unu)
            lung++;
        else
        {
            if(lung>lm)
                lm=lung;
            lung=0;
        }
    }
    cout<<lm;
     return 0;
}
