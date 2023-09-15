#include <cmath>
long long nroot(int n, long long x)
{
    float exp=(double)1/n;
    if (x<0) x=-x;
    if (x==0) return 0;
    else return pow(x,exp);
}
