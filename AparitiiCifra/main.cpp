#include <fstream>
using namespace std;
ifstream f("aparitiicifra.in");
ofstream g("aparitiicifra.out");
int k,c,p,sol,n;
int main()
{
    f>>k>>c;
    p=1;
    n=k;
    while(k) {
        if(k%10>c)
            sol=sol+(k/10+1)*p;
        if(k%10<c)
            sol=sol+(k/10)*p;
        if(k%10==c)
            sol=sol+(k/10)*p+n%p+1;
        k/=10;
        p*=10;
    }
    g<<sol;
    return 0;
}
