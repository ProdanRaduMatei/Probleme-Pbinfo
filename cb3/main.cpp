#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cb3.in");
ofstream g("cb3.out");
int v[10002], n, q, i, sp[10002],s;
int bsearch1 (int p, int u, int key) {
int m;
while (p < u){
m = (p + u) / 2;
if (sp[m] <= key)
p = m + 1;
else
u = m;
}
m = (p + u) / 2;
if (sp[m] > key)
-- m;
return m;
}
int main()
{
f >> n >> q;
for (i=1; i<=n; ++i) f >> v[i];
sort(v+1,v+n+1);
sp[1]=v[1];
for (i=2; i<=n; ++i) sp[i]=sp[i-1]+v[i];
for (i=1; i<=q; ++i)
{
f >> s;
g << bsearch1(1,n,s) << "\n";
}
}
