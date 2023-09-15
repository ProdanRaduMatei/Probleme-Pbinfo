#include <iostream>
#include <math.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    if((int)sqrt(n)==(float)sqrt(n))
        cout<<"DA";
    else
        cout<<"NU";
    return 0;
}
