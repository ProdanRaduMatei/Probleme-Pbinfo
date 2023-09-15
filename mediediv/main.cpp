#include <iostream>

using namespace std;

int n,d,NR,s,S1;
float ma,S;

int main()
{
    cin>>n;
    for(d=1; d<=n; d++) {
        if(n%d==0){
            s=s+d;
            NR++;
        }
    }
    ma=(float) s/NR;
    if(ma==(int)ma)
        cout<< ma;
    else {
    ma=ma*100;
    S1=(int)ma;
    S=( float) S1/100;
    cout << S;
    }

return 0;
}
