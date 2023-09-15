#include<bits/stdc++.h>
inline int Phi(int n)
{
    register int nr=1,d=2,p;
    while(n>1)
    {
        p=0;
        while(n%d==0)
            ++p,n/=d;
        if(p)
            nr*=(d-1)*pow(d,p-1);
        ++d;
        if(n>1 && d*d>n)
            d=n;
    }
    return nr;
}
