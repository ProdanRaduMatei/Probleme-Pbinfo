#include <fstream>

using namespace std;
ifstream in("pozmax.in");
ofstream out("pozmax.out");
int main()
{
    int n,i1=1,i2=1,i;
    float nr,m;
    in>>n>>m;
    for(i=2;i<=n;i++)
    {
        in>>nr;
        if(nr==m)
            i2=i;
        else if(nr>m)
        {
            i1=i;
            i2=i;
            m=nr;
        }
    }
    out<<i1<<" "<<i2;
    return 0;
}
