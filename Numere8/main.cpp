#include <fstream>
using namespace std;
int x,i,v[10020];
int main()
{
ifstream f("numere8.in");
ofstream g("numere8.out");
while(f>>x)
if(x<=9999) v[x]=1;
for(i=9999;i>=1;i--)
if(v[i]==0) g<<i<< " ";
f.close();
g.close();
return 0;
}
