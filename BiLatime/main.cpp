#include <bits/stdc++.h>
using namespace std;
ifstream fin("bilatime.in");
ofstream fout("bilatime.out");
vector<vector<int>> G(50001);
int n;
void citire(int nod, int ad){
    int x;
    fin >> x;
    n = max(n, ad);
    if(x != 0)
        G[ad].push_back(x);
    if(x) {
        citire(2 * nod, ad+1);
        citire(2 * nod + 1, ad+1);
    }
}
int main(){
    citire(1, 0);
    for(int i = 0; i <= n; ++i)
        for(auto x:G[i])
            fout << x << ' ';
    return 0;
}
