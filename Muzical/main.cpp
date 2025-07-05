#include <fstream>
using namespace std;
ifstream fin("muzical.in");
ofstream fout("muzical.out");
int main(){
    char x[5];
    int n,i,s=0;
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>x;
        if(x[0]=='d'&&x[2]=='1')
            s=s+0;
        if(x[0]=='r')
            s=s+1;
        if(x[0]=='m')
            s=s+2;
        if(x[0]=='f')
            s=s+3;
        if(x[0]=='s'&&x[1]=='o')
            s=s+4;
        if(x[0]=='l')
            s=s+5;
        if(x[0]=='s'&&x[1]=='i')
            s=s+6;
        if(x[0]=='d'&&x[2]=='2')
            s=s+7;
    }
    if(s%8==0)
        fout<<"do1";
    else if(s%8==1)
        fout<<"re";
    else if(s%8==2)
        fout<<"mi";
    else if(s%8==3)
        fout<<"fa";
    else if(s%8==4)
        fout<<"sol";
    else if(s%8==5)
        fout<<"la";
    else if(s%8==6)
        fout<<"si";
    else if(s%8==7)
        fout<<"do2";
    return 0;
}
