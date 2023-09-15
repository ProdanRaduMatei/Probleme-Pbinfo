#include <iostream>

using namespace std;

int main() {
    int a,b,num=0;
    cin>>a>>b;
    cout<<1;
    while(a!=1) {
        num++;
        a=a/10;
    }
    for(int i=1;i<=b*num;i++)
        cout<<0;
    return 0;
}
