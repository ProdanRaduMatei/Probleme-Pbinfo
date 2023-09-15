#include <fstream>
using namespace std;
ifstream f("subnumar.in");
ofstream g("subnumar.out");
int main()
{
int v[100],k = 0,x;
for ( int i = 0 ; i < 100 ; ++i )
v[i] = 0;
while ( f >> x )
{
while ( x > 9 )
{
v[x % 100]++;
x /= 10;
}
k++;
}
int maxim = -1;
for (int i = 99 ; i >= 10 ; --i )
if ( maxim < v[i] )
maxim = v[i];
for (int i = 99 ; i >= 10 ; --i )
if ( v[i] == maxim )
g << i << ' ';
return 0;
}
