#include <iostream>
#include <algorithm>
using namespace std;

int main(){
int n,c=0,i,j,k;
cin>>n;int v[n];
for(i=0;i<n;i++)cin>>v[i];
sort(v, v+n);
for(i=0;i<n-2;++i){
k=i+2;
for(j=i+1;j<n;++j){
while(k<n&&v[i]+v[j]>v[k])
++k;
c+=k-j-1;
}
}
cout<<c;
return 0;
}
