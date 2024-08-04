#include<fstream>
using namespace std;

ifstream fin("produscartezian2.in");
ofstream fout("produscartezian2.out");

int x[10],n,v[10];

void Read()
{
    int i;
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>v[i];
}

void Display()
{
    int i;
    for(i=1;i<=n;i++)
        fout<<x[i]<<" ";
    fout<<'\n';
}

void Backtracking(int k)
{
    if(k>n)
        Display();
    else
    {
        int i;
        for(i=1;i<=v[k];i++)
        {
            x[k]=i;
            Backtracking(k+1);
        }
    }
}

int main()
{
    Read();
    Backtracking(1);
}