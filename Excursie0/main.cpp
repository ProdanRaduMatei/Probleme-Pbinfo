#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int z,pb,pt,b,t,pozitie;
    cin>>z>>pb>>b>>pt>>t;
    pozitie=0;
    while(z!=0) {
    pb=pb+b;
    pt=pt+t;
    if(pb==pt)
        pozitie=pb;
    z=z-1;
    }
    if(pozitie!=0)
        cout<<pozitie;
    else
        cout<<-1;
    return 0;
}
