#include <fstream>
using namespace std;
int n, i, j;
long long c[42][42], x;
int sum(long long nr)
{
    int s = 0;
    while(nr) {
        s=s+nr%10;
        nr=nr/10;
    }
    return s;
}
bool prim(int nr)
{
    for(int p=2;p*p<=nr;p++)
        if(nr%p==0)
            return false;
    return true;
}
int main()
{
    ifstream f("vuli.in");
    ofstream g("vuli.out");
    f>>n;
    c[1][0]=c[1][1]=1;
    for(i=2;i<=n;i++) {
        c[i][0]=c[i][i]=1;
        for(j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    for(j=0;j<=n/2;j++) {
        x=c[n][j];
        if(prim(sum(x))||sum(x)==1)
            g<<x<<" ";
    }
    return 0;
}
