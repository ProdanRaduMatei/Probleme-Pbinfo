#include <bits/stdc++.h>
using namespace std;
ifstream fin("accesibil.in");
ofstream fout("accesibil.out");
int accesibil(long long n);
int caccesibil(long long n);
int nrcifre(long long n);
int main()
{

    int p,k,n;
    fin >> p >> k >> n;
    if(p == 1)
    {
        long long a = -1 , b=-1 , c = -1 , x;
        for(int i = 1 ; i <= n ; ++i)
        {
            fin >> x;
            if(accesibil(x) and x >= c)
            {
                c = x;
                if(c >= b) swap(c,b);
                if(b >= a) swap(a,b);
            }
        }
        fout << c << " " << b << " " << a;
    }
    if(p == 2)
    {
        int nr = 0;
        long long x;
        for(int i = 1 ; i <= n ; ++i)
        {
            fin >> x;
            if(!accesibil(x) and caccesibil(x)) nr++;
        }
        fout << nr;
    }
    if(p == 3)
    {
        long long Min = 0 , Max = 0 , q = 1;
        if(k == 9)
            fout << 123456789;
        else
        {
            for(int i = 1 ; i <= k ; i++)
            {
                Min = Min * 10 + i;
                Max += (10-i)*q;
                q *= 10;
            }
            fout << Min << " " << Max;
        }
    }
    if(p == 4)
        fout << (5-(k+1)/2) << " " << (5-k/2);
    return 0;

}
int accesibil(long long n)
{
    if(n<10)
        return 0;
    int k=n%10,c;
    while(n>9)
    {
        n/=10;
        c=n%10;
        if(c+1!=k)
            return 0;
        else
            k=c;
    }
    return 1;
}
int caccesibil(long long n)
{
    if(n<100)
        return 0;
    int nr=nrcifre(n);
    for(;nr;nr--)
    {
        int q=0;
        long long x=0,p=n,k=1;
        while(p!=0)
        {
            q++;
            if(q!=nr)
            {
                x+=k*(p%10);
                k*=10;
            }
            p/=10;
        }
        if(accesibil(x))
            return 1;
    }
    return 0;
}
int nrcifre(long long n)
{
    if(n<10)
        return 1;
    int nr=0;
    while(n!=0)
    {
        n/=10;
        nr++;
    }
    return nr;
}
