#include <iostream>

using namespace std;

int n,x[50],p[50],bin[50],lim,nrc0,nrc1;

void afisare ()
{
    for (int i=1; i<=lim; ++i) cout<<x[i];
    cout<<"\n";
}

bool valid (int k)
{
    int a=0,b=0;
    for (int i=1; i<=k; ++i){
        if (x[i]==0) a++;
        else b++;
    }
    if (a<=nrc0 && b<=nrc1) return true;
    return false;
}

void bectreching (int k)
{
    x[k]=0;
    if (valid(k))
        if (k<lim) bectreching(k+1);
        else afisare();
    x[k]=1;
    if (valid(k))
        if (k<lim) bectreching(k+1);
        else afisare();
}

int main()
{
    cin>>n;
    while(n){
        bin[++lim]=n%2;
        if (n%2==0) nrc0++;
        else nrc1++;
        n/=2;
    }
    bectreching(1);

    return 0;
}