#include <iostream>
#include <algorithm>
using namespace std;
//se declara variabilele
unsigned long long int n;
unsigned long long int m;
unsigned long long int minim,inf;
//codul principal
int main(){
    cin >> n >> m;
    minim = n;
    if(m < minim) {
        minim = m; //variabila minim va retine numarul de ani dupa care se opreste expansiunea
    }
    inf = minim * (minim + 1) / 2; //inf retine numarul de comitate infectate dupa oprirea expansiunii bacteriei
    cout << (n * m) - inf <<endl;
    return 0;
}//sfarsit program