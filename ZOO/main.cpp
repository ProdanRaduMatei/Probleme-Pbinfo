#include <fstream>
using namespace std;
ifstream f("zoo.in");
ofstream g("zoo.out");
int n,m,a[105][105];
long long s[105][105];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            f>>a[i][j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    int q;
    f>>q;
    while(q--)
    {
        int i1,j1,i2,j2;
        f>>i1>>j1>>i2>>j2;
        g<<s[i2][j2]-s[i2][j1-1]-s[i1-1][j2]+s[i1-1][j1-1]<<'\n';
    }
    return 0;
}
