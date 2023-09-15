#include <iostream>
using namespace std;
 int main()
{
long long n,k,x,y,S;
 cin>>n>>k;
x=k*(k-1)/2;
 y=n%k;
y=(y+1)*y/2;
 n=n/k;
 S=n*x+y;
 cout<<S<<endl;
return 0;
}
