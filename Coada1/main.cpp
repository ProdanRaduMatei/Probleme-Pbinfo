#include <fstream>

using namespace std;

int main()
{
int is[1000], elem = 0, m, x, aux;
char cs[10];
ifstream fin("coada1.in");
ofstream fout("coada1.out");
fin>>m;
while(m>0)
{
m--; fin>>cs>>x;
if(cs[0]=='p')
{
is[elem] = x; elem++;
for(int i = 0; i < elem-1; i++)
if(is[i] == x)
{
for(int j = 0; j < elem - i - 1; j++)
is[j] = is[i+j];
break;
}
}
else
{
aux=-1;
for(int i = 0; i < elem ; i++)
if(is[i]==x)
{ aux = i+1; break; }
fout<<aux<<endl;
}
}
return 0;
}
