#include <fstream>
using namespace std;
ifstream f("memory001.in");
ofstream g("memory001.out");
unsigned m,n,i,j,jmin;
unsigned long long int a,v[1001],minim,s;
int main()
{
	f>>m>>n;
	for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            f>>a;
            v[j]+=a;
        }
	minim=v[1];
	jmin=1;
	for(j=2;j<=n;j++)
        if(v[j]<minim)
        {
            minim=v[j];
            jmin=j;
        }
    g<<jmin;
    return 0;
}
