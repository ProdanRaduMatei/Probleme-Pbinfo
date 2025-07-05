#include <bits/stdc++.h>


using namespace std;

ifstream fin("firma.in");
ofstream fout("firma.out");

#define Inf 0x3f3f3f3f
using PI = pair<int , int>;
vector <PI> G[101];
int n , m , x , y , w , D[101] , mini , ind;

void init()
{
    for(int i = 1 ; i <= n ; i++)
        D[i] = Inf;
}

void dijkstra(int nod)
{
    priority_queue < PI , vector <PI> , greater<PI> > Q;
    D[nod] = 0;
    Q.push({0 , nod});
    while(!Q.empty())
    {
        int x = Q.top().first;
        int y = Q.top().second;
        Q.pop();
        if(x > D[y]) continue;
        for(auto& p:G[y])
        {
            int nodnou = p.first;
            int costnou = p.second;
            if(D[nodnou] > D[y] + costnou)
            {
                D[nodnou] = D[y] + costnou;
                Q.push({D[nodnou] , nodnou});
            }
        }
    }
}

int main()
{
    fin >> n >> m;
    for(int i = 1 ; i <= m ; ++i)
    {
        fin >> x >> y >> w;
        G[x].push_back({y , w});
        G[y].push_back({x , w});
    }
    mini = Inf;
    for(int i = 1 ; i <= n ; i++)
    {
        init();
        dijkstra(i);
        int sum = 0;
        for(int j = 1 ; j <= n ; j++)
            sum += D[j];
        if(sum < mini) mini = sum , ind = i;
    }
    fout << ind;
}
