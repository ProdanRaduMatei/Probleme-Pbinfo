#include <iostream>
#include <fstream>
using namespace std;
int v[1000];
int main()
{
    ifstream f("nrlipsa.in");
    ofstream g("nrlipsa.out");
    int num, a, b, nr=0, i;
    while (f >> num)
    {
        if (num>=100 && num<1000)
        { if (v[num]==0) {v[num]=1; ++nr;}}
    }
    if (900-nr<2) g << "NU";
    else
    {
        i=999;
        while (v[i]==1) --i;
        b=i; --i;
        while (v[i]==1) --i;
        a=i;
        g << b << " " << a;
    }
    return 0;
}
