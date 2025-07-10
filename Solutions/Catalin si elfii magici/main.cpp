#include <fstream>

using namespace std;

ifstream fin("elfii.in");
ofstream fout("elfii.out");

int x,y,z,k,p,Max=-1,n;
int main() {
    fin >> x >> y >> z;
    while(p!=6) {
        k=0;
        k=x*100+y*10+z;
        if(p%2==0)
            swap(y,z);
        if(p==1)
            swap(x,z),swap(y,z);
        if(p==3)
            swap(x,y),swap(y,z);
        p++;
        if(k%2==0 and k/100!=0) {
            if(k>Max)
                Max=k;
            n++;
        }
    }
    if(n==0)
        fout << "Poate data viitoare!";
    else
        fout << n << endl << Max;
    return 0;
}
