#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("divigrup.in");
ofstream fout("divigrup.out");
struct elem{int nr,nrdivizori;}v[201];
int a[1000][201];
int main(){
    int k,j,i,n,x,y,p,maxim=0,grup=0;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i].nr;
        v[i].nrdivizori=1;
        y=v[i].nr;
        x=2;
        while(y>1)
        {
            p=0;
            while(y%x==0)
            {
                p++;
                y=y/x;
            }
            v[i].nrdivizori*=(p+1);
            x++;
            if(x*x>y)
                x=y;
        }
        if(v[i].nrdivizori>maxim)
            maxim=v[i].nrdivizori;
    }
    for(i=1;i<=n;i++)
    {
        a[v[i].nrdivizori][0]++;
        a[v[i].nrdivizori][a[v[i].nrdivizori][0]]=v[i].nr;
    }
    for(i=1;i<=maxim;i++)
    {
        if(a[i][0])
            grup++;
        for(j=1;j<a[i][0];j++)
            for(k=j+1;k<=a[i][0];k++)
                if(a[i][j]>a[i][k])
                swap(a[i][j],a[i][k]);
    }
    fout<<grup<<'\n';
    for(i=maxim;i>=1;i--)
        if(a[i][0])
        {
            fout<<a[i][0]<<" ";
            for(j=1;j<=a[i][0];j++)
                fout<<a[i][j]<<" ";
            fout<<'\n';
        }
    return 0;
}
