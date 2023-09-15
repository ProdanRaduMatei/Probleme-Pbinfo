#include <fstream>
using namespace std;

int n,m,i,ii,j,jj,k,st,dr;
int a[1002][1002];
short x[1000005],y[1000005];
int x1,y1,x2,y2;

const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int main()
{
ifstream f("roboti.in");
ofstream g("roboti.out");
f>>n>>m;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
f>>a[i][j];
f>>x1>>y1>>x2>>y2;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
a[i][j]=-a[i][j];
for(i=0;i<=n+1;i++)
a[i][0]=a[i][m+1]=-1;
for(j=0;j<=m+1;j++)
a[0][j]=a[n+1][j]=-1;
st=dr=1;
x[dr]=x1,y[dr]=y1;
a[x1][y1]=1;
while(st<=dr)
{
i=x[st],j=y[st];
for(k=0;k<4;k++)
{
ii=i+dx[k],jj=j+dy[k];
if(a[ii][jj]==0)
{
a[ii][jj]=a[i][j]+1;
dr++;
x[dr]=ii,y[dr]=jj;
}
}
st++;
}
if(a[x2][y2]==0)
g<<-1;
else
g<<a[x2][y2]-1;
return 0;
}
