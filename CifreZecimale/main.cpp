#include <iostream>

using namespace std;

int k, linie, C, rest;

int main(){
    cin >> k;
    linie=k/20+1;
    if (k%2)
        C=linie;
    else {
        rest=k%20;
        if (rest==0)
            C=9;
        else
        C=(k%20)/2-1;
    }
    cout << C;
    return 0;
}
