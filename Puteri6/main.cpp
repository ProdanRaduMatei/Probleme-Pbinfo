#include <iostream>
#include <fstream>
using namespace std;
ifstream f("puteri6.in");
ofstream g("puteri6.out");
int n, suma, fr[10], num, nrzero, i, z=1, exista, v[10];
int main()
{
    for (i=0; i<10; ++i)
    {
        v[i]=z;
        z*=10;
    }
    f >> n;
    while (f >> num)
    {
        nrzero=0;
        while (num>1)
        {
            ++nrzero;
            num=num/10;
        }
    ++fr[nrzero];
    }
    for (int i=0; i<10; ++i)
    {
        suma=suma+fr[i];
        if (suma>=n) { num= v[i]; exista=1; break; }
    }
    if (exista) g << num;
    else g << "Nu exista";
}
