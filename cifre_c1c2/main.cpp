#include <iostream>

using namespace std;

int c1,c2,x[20];

void afisare()
{
    for (int i=1; i<=c1+c2; ++i) cout<<x[i];
    cout<<"\n";
}

bool valid (int k)
{
    int nrc1=0,nrc2=0;
    for (int i=1; i<=k; ++i)
        if (x[i]==c1) nrc1++;
        else nrc2++;
    if (nrc1<=c2 && nrc2<=c1) return true;
    else return false;
}

void bectreching (int k)
{
    x[k]=c1;
    if (valid(k))
    {
        if(k<c1+c2) bectreching(k+1);
        else afisare();
    }
    x[k]=c2;
    if (valid(k))
    {
        if(k<c1+c2) bectreching(k+1);
        else afisare();
    }
}

int main ()
{
    cin>>c1>>c2;
    if (c1>c2) swap(c1,c2);
    bectreching(1);

    return 0;
}