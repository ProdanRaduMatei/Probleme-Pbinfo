#include <bits/stdc++.h>
using namespace std;
ifstream fin("firma1.in");
ofstream fout("firma1.out");
int n, d[101], c[101], r, p[101];
vector<vector<int>> G(101); queue<int> Q; void lee(){ while(!Q.empty()){ int x = Q.front(); bool ok = true; for(auto i:G[x]) if(!p[i]) ok = false; if(!ok){ Q.pop(), Q.push(x); continue; } if(!p[x]){ int sum=0, cnt=0; for(auto i:G[x]){ sum += c[i]; cnt++; } p[x] = 1; if(cnt > 0){ int s = sum / cnt; if(s * cnt != sum) s++; c[x] += s; } Q.push(d[x]); } Q.pop(); } fout << c[r]; } int main(){ fin >> n; for(int i = 1; i <= n; ++i){ fin >> d[i]; if(d[i] != 0) G[d[i]].push_back(i); else r = i; } for(int i = 1; i <= n; ++i) fin >> c[i]; for(int i = 1; i <= n; ++i){ int cnt = 0; for(auto j:G[i]) if(d[i] != j) cnt++; if(!cnt) Q.push(d[i]), p[i] = 1; } lee(); return 0; }
