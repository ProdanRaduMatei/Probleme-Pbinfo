#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; ++i) {
        int n , m;
        int a[1001] , b[1001];
        cin >> n;
        for(int j = 0 ; j < n ; ++j)
            cin >> a[j];
        cin >> m;
        for(int j = 0 ; j < m ; ++j)
            cin >> b[j];
        int cnt=0;
        int ok=0;
        for(int j = 0 ; j < m ; ++j) {
            int s=0;
            for(int k = ok ; k < n ; ++k) {
                s+=a[k];
                ok++;
                if(s >= b[j])
                    break;
            }
            if(b[j]==s)
                cnt++;
        }
        if(cnt==m && ok==n)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
