#include <bits/stdc++.h>
using namespace std;
ifstream fin("sumsubmax.in");
ofstream fout("sumsubmax.out");
vector<int> G[101];
int n , p , x , y , k , T[102] , P[101] , C[101] , d[101];
int dfs(int x) {
    P[x] = 1;
    d[x] = C[x];
    for(auto i:G[x])
        if(!P[i])
            d[x] += dfs(i);
    return d[x];
}
int main() {
    fin >> n;
    for(int i = 1 ; i <= n ; i++) {
        fin >> T[i];
        if(T[i] != 0)
            G[T[i]].push_back(i);
        if(T[i] == 0)
            p = i;
    }
    for(int i = 1 ; i <= n ; i++)
        fin >> C[i];
    d[p] = dfs(p);
    int maxi = -9999;
    for(int i = 1 ; i <= n ; i++)
        if(d[i] > maxi)
            maxi = d[i];
    for(int i = 1 ; i <= n ; i++)
        if(d[i] == maxi)
            fout << i << " ";
}
