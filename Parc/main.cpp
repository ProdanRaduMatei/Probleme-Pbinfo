#include <bits/stdc++.h>


using namespace std;

ifstream fin("parc.in");
ofstream fout("parc.out");

const int Inf = 0x3f3f3f3f;
using PI  = pair<int, int>;
using VP  = vector<PI>;
using VVP = vector<VP>;
using VI  = vector<int>;

int n , p , m , mini = 999999999;
VI d;
VVP G;

void Dijkstra(int x, VI& d)
{
    d = VI(n + 1, Inf);
    priority_queue<PI, vector<PI>, greater<PI>> Q;
    d[x] = 0;
    Q.push({0, x});
    int y, w, dist;
    while (!Q.empty())
    {
        x = Q.top().second;
        dist = Q.top().first;
        Q.pop();
        if (dist > d[x])
            continue;

        for (auto& p : G[x])
        {
            y = p.first;
            w = p.second;
            if (d[y] > d[x] + w)
            {
                d[y] = d[x] + w;
                Q.push({d[y], y});
            }
        }
    }
}


int main()
{
    int x , y , w , a , q , rez;
    fin >> n >> m >> p;

    G = VVP(n + 1);
    for(int i = 1 ; i <= m ; i++)
    {
        fin >> x >> y >> w;
        G[x].emplace_back(y , w);
        G[y].emplace_back(x , w);
    }
    fin >> q;
    for(int i = 1 ; i <= q ; i++)
    {
        fin >> a;
        Dijkstra(a, d);
        if(d[p] < mini) mini = d[p] , rez = a;
    }
    fout << rez;
}
