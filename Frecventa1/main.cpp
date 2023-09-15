#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct data
{
    int nr,
    ap;
}v[101];
bool descr(const data &a, const data &b)
{
    if (a.ap != b.ap) return (a.ap>b.ap);
    return (a.nr<b.nr);
}
int main()
{
    ifstream f("frecventa1.in");
    ofstream g("frecventa1.out");
    int n, i, num;
    f >> n;
    for (i=0; i<100; ++i) v[i].nr=i;
    for (i=1; i<=n; ++i)
    {
        f >> num;
        ++v[num].ap;
    }
    sort(v, v+100, descr);
    for (i=0; i<100; ++i)
        if (v[i].ap) g << v[i].nr << " ";
    return 0;
}
