#include <iostream>
using namespace std;
void citire(int &n, int a[1001]);
int palindrom(int n, int a[1001]);
int nr_permutari_ciclice(int n, int a[1001]);
void afisare(int n, int a[1001]);
int main()
{
    int n, a[1001];
    citire(n,a);
    afisare(n,a);
    return 0;
}
void citire(int &n, int a[1001])
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
int palindrom(int n, int a[1001])
{
    for(int i=1;i<=n/2;i++)
        if(a[i]!=a[n-i+1])
            return 0;
    return 1;
}
int nr_permutari_ciclice(int n, int a[1001])
{
    int permutari_ciclice=0;
    int aux;
    int i;
    while(permutari_ciclice<n){
        if(palindrom(n,a))
            return permutari_ciclice;
        permutari_ciclice++;
        aux=a[1];
        for(i=1;i<n;i++)
            a[i]=a[i+1];
        a[n]=aux;
    }
    return n;
}
void afisare(int n, int a[1001])
{
    int p=nr_permutari_ciclice(n,a);
    if(p!=n)
        cout<<"Da, "<<p;
    else cout<<"Nu";
}
