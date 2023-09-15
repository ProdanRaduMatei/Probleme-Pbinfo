#include <iostream>
using namespace std;

int x,a,b,y,c,d,m,i;
int main()
{
    cin>>x>>a>>b>>y>>c>>d;
    if(a > b)
        swap(a,b);
    if(c > d)
        swap(c,d);
    if(a % x == 0)
        i = b / x - a / x + 1;
    else
        i = b / x - a / x;
    if(c % y == 0)
        m = d / y - c / y + 1;
    else
        m = d / y - c / y;
    if(m > i)
        cout<<"Maria "<<m;
    else if(m < i)
        cout<<"Ioana "<<i;
    else if(i == m)
        cout<<"Egalitate "<<m;
}