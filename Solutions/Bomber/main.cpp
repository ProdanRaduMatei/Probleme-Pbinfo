#include<fstream>
#include<cmath>

using namespace std;

ifstream fin("bomber.in");
ofstream fout("bomber.out");

struct bomb
{
    int x,y,p,on;
}v[101];

inline int comp(int ind,int j)
{
    return sqrt((v[ind].x-v[j].x)*(v[ind].x-v[j].x)+(v[ind].y-v[j].y)*(v[ind].y-v[j].y))<=v[ind].p;
}

inline void exploziv(int ind,int n)
{
    v[ind].on=1;
    for(int i=1;i<=n;i++)
        if(!v[i].on) {
            if(comp(ind,i))
                exploziv(i,n);
        }
}

int main()
{
    static int n,ind,k;
    fin>>n>>ind;
    for(int i=1;i<=n;i++)
        fin>>v[i].x>>v[i].y>>v[i].p;
    exploziv(ind,n);
    for(int i=1;i<=n;i++)
        if(!v[i].on)
            k++;
    fout<<k;
}
