#include <bits/stdc++.h>

using namespace std;

double x1, x2, y, y2, r1, r2, d, k;

int main(){
    cin>>r1>>x1>>y>>r2>>x2>>y2;
    d=sqrt((x2-x1)*(x2-x1)+(y2-y)*(y2-y));
    if(r1==r2 && y==y2 && x1==x2)
        cout<<"infinit";
    else {
        if(d==abs(r1-r2) || d==r1+r2 )
            cout<<1;
        else if (d<r1+r2 && r1+d>r2 && d+r2>r1)
            cout<<2;
        else
            cout<<0;
    }
    return 0;
}
