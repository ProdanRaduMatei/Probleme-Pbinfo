#include<fstream>
using namespace std;

ifstream fin("orademate.in");
ofstream fout("orademate.out");

int x[10],c,n;

void Read()
{
    fin>>c>>n;
}

void Display()
{
    int i;
    for(i=1;i<=n;i++)
        fout<<x[i];
    fout<<'\n';
}

int Valid(int k)
{
    if(x[1]==0 && k>1)
        return 0;
    if(c==1)
    {
        int i;
        for(i=1;i<=k;i++)
            if(i%2==x[i]%2)
                return 0;
        return 1;
    }
    else
    {
        int i;
        for(i=1;i<k;i++)
        {
            if(i==x[i])
                return 0;
            if(x[i]>x[i+1])
                return 0;
        }
        if(x[k]==k)
            return 0;
        return 1;
    }

}

void Backtracking(int k)
{
    if(k>n)
        Display();
    else
    {
        int i;
        for(i=0;i<=9;i++)
        {
            x[k]=i;
            if(Valid(k))
                Backtracking(k+1);
        }
    }
}

int main()
{
    Read();
    Backtracking(1);
}