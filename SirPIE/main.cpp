#include <fstream>
#include <algorithm>
using namespace std;
#define NR 21
ifstream f("sirpie.in");
ofstream g("sirpie.out");
int x[NR],a[NR],n,k;

int cmmdc(int a,int b)
{
    int t;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

void init(int k)
{
    x[k]=0;
}

int succesor(int k)
{
    if (x[k]<n)
        return 1;
    else
        return 0;
}

int continuare(int k)
{
    for(int i=1;i<k;i++)
        if(x[k]==x[i])
            return 0;
    if(k>1)
    {
        if(cmmdc(a[x[k]],a[x[k-1]])==1)
            return 1;
        else
            return 0;
    }
    return 1;
}

int solutie(int k)
{
    if (k==n+1)
        return 1;
    else
        return 0;
}

void afisare()
{
    for (int i=1;i<=n;i++)
        g<<a[x[i]]<<' ';
    g<<'\n';
}

void backtracking()
{
int k;
k=1;
init(1);
while(k)
    if (solutie(k))
    {
        afisare();
        k--;
    }
    else
        if (succesor(k))
        {
            x[k]++;
            if (continuare(k))
                k++;
        }
        else
        {
            init(k);
            k--;
        }
}

int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        f>>a[i];
    sort(a+1,a+n+1);
    backtracking();
    return 0;
}
