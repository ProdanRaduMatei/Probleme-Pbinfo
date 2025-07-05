#include <bits/stdc++.h>
using namespace std; int main() { int n , m , ok = 0 , f[1000000]={0}; cin >> n >> m; int a[101][101]; for(int i= 1 ; i <= n ; ++i) { for(int j = 1 ; j <= m ; ++j) { cin >> a[i][j]; f[a[i][j]]++; } } for(int i = 999999 ; i >= 1 && ok ==0 ; i--) { if(f[i]>=2) cout << i , ok =1; } if(ok==0) cout << "IMPOSIBIL"; }
