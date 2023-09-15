#include <iostream>
using namespace std;
long long v[100005];
int main(){
    long long n,nrsecv=0,c;
    cin >> n;
    for (int i = 1; i<=n; i++)
        cin >> v[i];
    for (int i = 1; i<=n; i++) {
        c = 1;
        while (v[i] == v[i+1] && i+1<=n) {
            c++;
            i++;
        }
        nrsecv+=c*(c+1)/2;
    }
    cout << nrsecv;
}
