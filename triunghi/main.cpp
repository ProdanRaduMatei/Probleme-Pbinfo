#include <iostream>

using namespace std;

double a,b,c;

int main()
{
    cin>>a>>b>>c;
    if((a<b+c)&&(b<a+c)&&(c<a+b))
        cout<<"da";
    else
    cout<<"nu";
    return 0;
}
