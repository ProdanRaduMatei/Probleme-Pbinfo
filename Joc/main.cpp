#include <bits/stdc++.h>
using namespace std;
ifstream fin("joc.in");
ofstream fout("joc.out");
using VVP = vector <vector <pair<int , int> > >;
using VI = vector<int>;
using PI = pair<int, int>;
VI d;
VVP G;
const int Inf = 0x3f3f3f3f;
int cer , n , s , f , C[50001] , cate , x , T[50001] , cnt , rez[50001];
void Dijkstra(int x) {
    d = VI(n + 1, Inf);
    priority_queue, greater> Q;
    int y , cost , dist;
    d[x] = 0;
    Q.push({0 , x});
    while(!Q.empty()) {
        x = Q.top().second;
        dist = Q.top().first;
        Q.pop();
        if(dist > d[x])
            continue;
        for(auto& p : G[x]) {
            y = p.first;
            cost = p.second;
            if(d[y] > d[x] + cost) {
                d[y] = d[x] + cost;
                Q.push({d[y] , y});
                T[y] = x;
            }
        }
    }
}
int main() {
    fin >> cer >> n >> s >> f;
    G = VVP(n + 1);
    for(int i = 1 ; i <= n ; i++)
        fin >> C[i];
    for(int i = 1 ; i <= n ; i++) {
        fin >> cate;
        for(int j = 1 ; j <= cate ; j++) {
            fin >> x;
            int cost = max(C[i] , C[x]) / min(C[i] , C[x]);
            G[i].push_back({x , cost});
        }
    }
    Dijkstra(s);
    if(cer == 1)
        fout << d[f];
    else {
        int poz = T[f];
        rez[++cnt] = f;
        while(poz != 0) {
            rez[++cnt] = poz;
            poz = T[poz];
        }
        fout << cnt << '\n';
        for(int i = cnt ; i >= 1 ; i--)
            fout << rez[i] << " ";
    }
}
