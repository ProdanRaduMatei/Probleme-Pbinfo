#include <bits/stdc++.h>
using namespace std;
int main() {
    char c;
    int n , a[1001] , b[1001] , f[1001] , b1 = 0, f1 = 0 , minn = 1000 , maxx = 0 , cf = 0 , cb = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c >> a[i];
        if(c=='F')
            f[++f1] = a[i];
        else
            b[++b1] = a[i];
    }
    for(int i = 1; i <= f1 ; i++)
        if(f[i] > maxx)
            maxx = f[i];
    for(int i = 1; i < b1 ; i++)
        if(b[i] < minn)
            minn = b[i];
    for(int i = 1; i <= f1; i++)
        if(f[i] < minn)
            cf++;
    for(int i = 1; i <= b1; i++)
        if(b[i] > maxx)
            cb++;
    cout<<cf << " " << cb;
    return 0;
}
