#include <fstream>

using namespace std;

ifstream fin("parcare.in");
ofstream fout("parcare.out");

int z1,z2,l1,l2,h1,h2,m1,m2,t,o;
int rz,rh,rm,rt,sum;

int main() {
    fin >> z1 >> l1 >> h1 >> m1;
    fin >> z2 >> l2 >> h2 >> m2;
    fin >> t;
    fin >> o;
    if(z2<z1){
        if(l1==1 or l1==3 or l1==5 or l1==7 or l1==8 or l1==10 or l1==12)
            rz=z2+31-z1;
        else if(l1==4 or l1==6 or l1==9 or l1==11)
            rz=z2+30-z1;
        else if(l1==2)
            rz=z2+28-z1;
    }
    else
        rz=z2-z1;
    if(h2<h1) {
        rz--;
        if(m2>=m1)
            rh=h2+24-h1;
        else if(m2<m1)
            rh=h2+24-h1-1;
    }
    else {
        if(m2>=m1)
            rh=h2-h1;
        else if(m2<m1)
            rh=h2-h1-1;
    }
    if(m2<m1)
        rm=m2+60-m1;
    else if(m2>=m1)
        rm=m2-m1;
    rt=rz*1440+rh*60+rm;
    if(o==1)
    fout << rt;
    else if(o==2) {
        if(rt<15) fout << "0";
        else {
            if(rt%60==0)
                sum=(rt/60)*t;
            else
                sum=(rt/60+1)*t;
            fout << sum;
        }
    }
    return 0;
}
