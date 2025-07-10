#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>

using namespace std;

ifstream fin("competitie.in");
ofstream fout("competitie.out");

vector<int> g[1001], deg, sol;
unordered_map<int, int> mp, mc;
int edge, vertex;

int main() {
    ios_base::sync_with_stdio(false);
    fin >> vertex >> edge;
    deg = vector<int>(vertex + 1);
    for (int i = 0; i < edge; i++) {
        int x, y;
        fin >> x >> y;
        mp[x] = 1;
        mp[y] = 1;
        g[x].push_back(y);
        deg[y]++;
    }
    set<int> coada;
    for (auto i : mp)
        if (!deg[i.first])
            coada.insert(i.first);
    while (coada.size()) {
        int node = *coada.begin();
        coada.erase(node);
        mc[node] = 1;
        sol.push_back(node);
        for (auto i : g[node]) {
            deg[i]--;
            if (!deg[i])
                coada.insert(i);
        }
    }
    if (edge) {
        for (int i = 1; i < *sol.begin(); i++)
            if (!mc[i]) {
                fout << i << " ";
                mc[i] = 1;
            }
        fout << *sol.begin() << " ";
        for (int i = 1; i < sol.size(); i++) {
            for (int j = sol[i - 1]; j < sol[i]; j++)
                if (!mc[j]) {
                    fout << j << " ";
                    mc[j] = 1;
                }
            fout << sol[i] << " ";
        }
        for (int i = *(sol.end()-1); i <= vertex; i++)
            if (!mc[i])
                fout << i << " ";
    }
    else
        for (int i = 1; i <= vertex; i++)
            fout << i << " ";
    return 0;
}