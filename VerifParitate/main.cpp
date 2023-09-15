#include <iostream>
#include <bitset>
using namespace std;
int n;
unsigned long long x;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
//        cout<<(x & 1)<<" ";
        bitset<64>bit(x);
        cout<<bit[0]<<" ";
    }
    return 0;
}
