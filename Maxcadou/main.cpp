#include <fstream>
using namespace std;
ifstream f("maxcadou.in");
ofstream g("maxcadou.out");
long long i,n,n2,c;
int main()
{
    f>>n;
    for(i=9;i>=0;i--)
    {
        n2=n;
        while(n2!=0)
        {
            c=n2%10;
            if(c==i)
                g<<i;
            n2=n2/10;
        }
    }
    return 0;
}
