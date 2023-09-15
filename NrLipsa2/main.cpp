#include <fstream>
using namespace std;
ifstream fin("nrlipsa2.in");
ofstream fout("nrlipsa2.out");
int i,n,x,j,y,v[201];
int main()
{
    while (fin>>x)
    {
        if (x<=100 && x>=-100 )
        v[x+100]=1;
    }
    for (i=0;i<=200;i++)
    {
        if (v[i]==0)
        {
            y=1;
            fout<<(i-100);
            i=201;
        }
    }
    if (!y)
        fout<<"nu exista";
}
