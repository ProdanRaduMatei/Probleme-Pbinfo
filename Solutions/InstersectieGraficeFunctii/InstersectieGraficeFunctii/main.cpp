#include <bits/stdc++.h>
using namespace std;

int main() {
    double a,b,c,d,x,y;
    cin>>a>>b>>c>>d;
    if(a==c && b==d) {
        cout<<"Grafice echivalente";
        return 0;
    }
    else if(a==c) {
        cout<<"Grafice paralele";
        return 0;
    }
    x=(d-b)/(a-c);
    y=(a*x+b);
    cout<<fixed<<setprecision(2)<<x<<" "<<y;
}