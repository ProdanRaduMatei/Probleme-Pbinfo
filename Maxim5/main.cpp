#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("maxim5.in");
    ofstream g("maxim5.out");
    int a, lungmin, leng, maxl, M;
    f >> a;
    maxl=a; leng=1;
    while (a!=0)
    {
        f >> a;
        if (a!=0) {++leng; if (a>maxl) maxl=a;}
    }
    lungmin=leng; M=maxl;
    while (!f.eof())
    {
        f >> a;
        if (a) {
            maxl=a; leng=1;
            while (a!=0)
            {
            f >> a;
            if(a!=0) {
                ++leng;
                if (a>maxl)
                    maxl=a;
            }
            }
            if (leng<lungmin) {
                lungmin=leng;
                M=maxl;
            }
            else if (leng==lungmin && maxl>M)
                M=maxl;
            }
    }
    g << M << "\n";
    return 0;
}
