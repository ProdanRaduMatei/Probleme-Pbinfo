#include <iostream>
using namespace std;
unsigned n,i,j,t=0,f1=1,f2=1,f;
int main() {
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            t++;
            f1=f2;
            f2=f;
            f=(f1+f2)%10;
            cout<<f<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
