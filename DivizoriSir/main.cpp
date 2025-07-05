#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long int n,x,i,p,d,k;
    cin>>n;
    for(i=0;i<n;i++) {
        k=1;d=2;
        x=i*pow(2,i)+1;
        while(x>1) {
            p = 0;
            while(x%d==0) {
                p++;
                x=x/d;
                }
            k=k*(p+1);
            d++;
            if(x>1 && d * d > x)
                d = x;
        }
        cout<<k<<" ";
    }
    return 0;
}
