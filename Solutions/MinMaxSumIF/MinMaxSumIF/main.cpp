#include <bits/stdc++.h>

using namespace std;

int a,b;
int main()
{
    cin>>a>>b;
   if((a/10)%10==(b/10)%10)cout<<a+b;
   else if((a/10)%10>(b/10)%10)cout<<a;
   else cout<<b;

    return 0;
}