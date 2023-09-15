#include <iostream>

using namespace std;

int main() {
    int n,b;
    long long int x;
    cin>>n;
    for(int i = 0; i < n;i++){
        cin >> x >> b;
        cout << ((x & (1<<b))>>b) <<"\n";
    }
    return 0;
}
