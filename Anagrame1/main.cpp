#include <fstream>
#include <cstring>

using namespace std;

ifstream is("anagrame1.in");
ofstream os("anagrame1.out");

int n;
char v[100],st[50], p[50];

void scrie()
{
    int i;
    {
        for(i=1;i<=n;i++)
            os<<v[st[i]-1];
        os<<'\n';
    }
}

void back(int k)
{
    for(int i=1;i<=n;i++)
    if(!p[i])
        {
            st[k]=i;
            p[i]=1;
            if(k==n) scrie();
            else back(k+1);
            p[i]=0;
        }
}

int main()
{
    int i;
    is.get(v,1000);
    n=strlen(v);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(v[i]>v[j])
            {
                char aux=v[i]; v[i]=v[j]; v[j]=aux;
            }
    back(1);
    return 0;
}
