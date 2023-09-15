#include <bits/stdc++.h>
using namespace std;
ifstream fin("bazine.in");
ofstream fout("bazine.out");

int n , m , x , y , v[101];

vector<int> G[101];
vector<vector <int> > CC;

void dfs(int nod, vector<int> &C) {
    v[nod] = 1;
    C.push_back(nod);
    for(auto y : G[nod])
        if(v[y] == 0)
            dfs(y,C);
}
int main() {
    fin >> n >> m;
    for(int i = 1 ; i <= m ; i++) {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1; i <= n ; i++)
        if(!v[i]) {
            CC.push_back(vector());
            dfs(i,*(CC.end()-1));
        }
    fout << CC.size();
    return 0;
}

