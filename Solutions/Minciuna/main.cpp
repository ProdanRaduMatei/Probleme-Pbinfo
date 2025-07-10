#include <iostream>
using namespace std;
int main()
{
    int x,y,a;
    cin>>x>>y;
    while(x>y) {
        a=x;
        x=y;
        y=a;
    }
    if(y-x!=1) cout<<"minciuna";
    else
    {
        if(x%2==0) cout<<"Andrei e mai responsabil";
        else cout<<"minciuna";
    }
    return 0;
}
