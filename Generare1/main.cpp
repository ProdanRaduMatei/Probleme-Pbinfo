#include <bits/stdc++.h>
using namespace std; int main() { int n , a[25000] , p = 0; cin >> n; while(n != 4) { if(n % 10 == 4) {a[p] = 1;p++;n /= 10;} else if(n % 10 == 0) {a[p] = 2; p++; n /= 10;} else {a[p] = 3; p++ ; n *= 2;} } for(int i = p - 1 ; i >= 0 ; --i) cout << a[i] << " "; }
