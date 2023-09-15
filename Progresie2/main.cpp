#include <bits/stdc++.h>
using namespace std;
int main(){
    int a1, r, n,x,y;
    cin>>a1>>r>>n;
    x=a1;
    for(int i=1;i<=n;i++){
        y=x;
        for(int j=1;j<=n;j++){
            cout<<y<<" ";
            y=y+n*r;
        }
        cout<<'\n';
        x=x+r;
    }
    return 0;
}
