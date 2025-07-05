#include <iostream>

using namespace std;

long long a,b,s,dif,s1,s2, mij;

int main()

{
    cin >> a >> b;
    if (a>b) dif=a-b;
    else dif=b-a;
    mij=dif/2;
    if (mij%2==0) s1=(mij/2)*(1+mij);
        else s1=mij*((1+mij)/2);
    if (dif%2==0)
        s=2*s1;
    else {
        if ((mij+1)%2==0)
            s2=((mij+1)/2)*(2+mij);
        else s2=((2+mij)/2)*(mij+1);
            s=s1+s2;
    }
    cout << s;
    return 0;
}
