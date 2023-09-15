#include <iostream>
#include <fstream>
using namespace std;
int n,i,mic=9,mare=9, m[100];
int main(){
    ifstream filein;
    filein.open("nrlipsa1.in");
    ofstream fileout;
    fileout.open("nrlipsa1.out");
    i=0;
    while(i<100){
        m[i]=0;
        i++;
    }
    while(!filein.eof()){
        filein>>n;
        if(n>9 && n<100)m[n]=1;
    }
    i=10;
    while(i<100){
        if(m[i]==0){
            mic=i;
            i=100;
        }
        i++;
        i++;
    }
    i=98;
    while(i>9){
        if(m[i]==0){
            mare=i;
            i=9;
        }
        i--;
        i--;
    }
    if(mic!=mare)fileout<<mic<<" "<<mare;
    else fileout<<"nu exista";
    filein.close();
    fileout.close();
}
