#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("lascoala.in");
ofstream g("lascoala.out");
int n, k, i, j, p, prem;
int main()
{
    f >> n;
    k=n-1;
    while (sqrt(k)!=sqrt(k)) --k;
    prem=n-k;
    g << prem << "\n";
    n=n-prem;
    p=sqrt(k);
    for (i=1; i<=p; ++i)
    {
        for (j=1; j<=p; ++j)
            {g << n << " "; --n;}
        g << "\n";
    }
}
