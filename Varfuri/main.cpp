#include <iostream>
using namespace std;
int main() {
    unsigned n,a[1000],i,s=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=2;i<n;i++)
        if(a[i]>a[i-1]&&a[i]>a[i+1])
        s+=a[i];
    cout<<s;
    return 0;
    }
