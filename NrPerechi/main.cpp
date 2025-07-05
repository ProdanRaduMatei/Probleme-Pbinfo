#include <iostream>

using namespace std;

unsigned int nr_perechi(unsigned int n)
{
    unsigned int exp, i, np=1, a=n;
    for (i=2; i*i<=a; ++i)
    {
        exp=0;
        while (a%i==0)
        {
            ++exp;
            a/=i;
        }
        if (exp!=0) np=np*(2*exp+1);
    }
    if (a!=1) np*=3;
    return np;
}

int main()
{
    unsigned int n, x, i;
    cin >> n;
    for (i=1; i<=n; ++i)
    {
        cin >> x;
        cout << nr_perechi(x) << " " ;
    }
    return 0;
}
