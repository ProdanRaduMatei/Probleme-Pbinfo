#include <bits/stdc++.h>


using namespace std;

ifstream fin("gears.in");
ofstream fout("gears.out");

int n , x , y , m , p , d[1001] , v[1001];
vector <int> G[1001];

void bfs(int s)
{
    queue <int> Q;
    v[s] = 1;
    d[s] = 1;
    Q.push(s);
    while(!Q.empty())
    {
        int x = Q.front();
        for(int i : G[x])
            if(!v[i])
            {
                Q.push(i);
                v[i] = 1;
                d[i] = d[x] + 1;
            }
        Q.pop();
    }
}


int main()
{
    fin >> n >> p;
    while(fin >> x >> y)
    {
        G[x].push_back(y);
        G[y].push_back(x);
    }

    bfs(p);

    for(int i = 1 ; i <= n ; i++)
        if(d[i] % 2 == 1)
            fout << "D";
        else
            fout << "S";
}
