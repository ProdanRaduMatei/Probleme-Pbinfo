#include <bits/stdc++.h>
using namespace std; char s[300]; int main() { cin >> s; int l = strlen(s); int cnt = 0; while(l%2==0) { bool ok = true; for(int i = 0 ; i < l/2 ; ++i) if(s[i]!=s[l-i-1]) ok=false; if(ok) { cnt++; l/=2; } else break; } cout << cnt; return 0; }
