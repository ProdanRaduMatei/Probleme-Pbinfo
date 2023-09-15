#include <bits/stdc++.h>
using namespace std; int main() { int n , p; cin >> n >> p; int a[100]; for(int i = 1 ; i <= n ; ++i) a[i]=i , p-=i; int parte=p/n; int rest=p%n; for(int i = 1 ; i <= n ; ++i) a[i]+=parte; for(int i = n ; i >= 1 && rest; --i) { a[i]+=1; rest--; } for(int i = 1 ; i <= n ; ++i) cout << a[i] << ' '; return 0; }
