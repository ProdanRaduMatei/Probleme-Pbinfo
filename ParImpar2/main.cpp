#include <iostream>
#include <fstream>

using namespace std;

ifstream f("parimpar2.in");
ofstream g("parimpar2.out");

int n,i,p,x=0,y=0,a,b;

int main() {
    f>>i>>p;
    while(f>>n) {
        if(n%2==0) {
            x++;
            if(x==p) {
                a=n;
                x++;
            }
        }
        if(n%2==1) {
            y++;
            if(y==i) {
                b=n;
                y++;
            }
        }
    }
    if(x<p or y<i)
        g<<"Nu Exista";
    else
        g<<a<<" "<<b;
    return 0;
}
