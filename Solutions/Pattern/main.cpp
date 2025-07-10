#include <iostream>
#include <cmath>
using namespace std;
int n,a[1025][1025];

void pattern(int xs,int ys,int xj,int yj)
{

     int xm=(xs+xj-1)/2,ym=(ys+yj-1)/2;
            for(int i=xs;i<=xm;++i) // Scriu patern I
                for(int j=ys;j<=ym;++j)
                    a[i][j]=1;
    if(xj-xs+1>2)
    {//Impart matricea in 4 submatrici
        pattern(xs,ys,xm,ym); //Stanga-Sus
        pattern(xm+1,ym+1,xj,yj); //Dreapta-Jos
        pattern(xs,ym+1,xm,yj); // Dreapta-Sus
        pattern(xm+1,ys,xj,ym); //Stanga-Jos
    }
}

int main()
{
    cin>>n;
    n=1<<n; // Calculam p=2^n prin deplasari la stanga (1=2^0)
    pattern(1,1,n,n);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
