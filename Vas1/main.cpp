#include<iostream>

using namespace std;

int main() {
    float x;
    int t,y,i,T=0;
    cin>>x>>t>>y>>i;
    while(x>y) {
        T+=t;
        x-=x/i;
    }
    cout<<T;
    return 0;
}
