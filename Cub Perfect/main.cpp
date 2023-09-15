#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long long x[100];
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>x[i];
    for(i=1;i<=n;i++){
        if(int(cbrt(x[i]))*int(cbrt(x[i]))*int(cbrt(x[i]))==x[i])
            cout<<"DA"<<endl;
        else
            cout<<"NU"<<endl;
    }
    return 0;
}
