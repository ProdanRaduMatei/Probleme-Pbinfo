#include <bits/stdc++.h>
using namespace std; int main() { int a[101][101] , n , m , cnt = 0; cin >> n >> m; for (int i = 1 ;i <= n ; ++i) for(int j = 1 ; j <= m ; ++j) cin >> a[i][j]; for(int i = 1 ; i < n ; i ++) for(int k = i+1 ; k <= n ; k++) { int ok = 0; for(int j = 1 ; j <= m ; j ++) if(a[i][j] != a[k][j]) ok = 1; if(ok == 0) cnt ++; } cout << cnt; return 0; }
