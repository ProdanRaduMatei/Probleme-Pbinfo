#include <iostream>
#include <fstream>
using namespace std;
ifstream f("intervale5.in");
ofstream g("intervale5.out");
int v[102], i, x, y, gasit, num;
int main()
{
    while (f >> num)
        ++v[num];
    i=0; while (v[i]==0) ++i;
    while (i<99)
    {
        while (v[i]!=0 && i<99) ++i;
        if (i<100)
        {
            x=i-1;
            while (v[i]==0 && i<101) ++i;
                if (i<101)
                {
                    y=i;
                    if (y-x>=2)
                    {g << x << " " << y << "\n";
                    gasit=1;}
                }
        }
    }
    if (gasit==0) g << "nu exista";
}
