#include <bits/stdc++.h>


using namespace std;

int n , m , s , x , y , v[101] , d[101] , p , cnt , sg[101] , k , vi , q , rez[1001];
vector <int> G[101];

void bfs(int s , int q)
{
    queue <int>Q;
    Q.push(s);
    v[s] = 1;
    d[s] = 1;
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for(int i : G[x])
            if(!v[i] && (sg[i] || i == q))
            {
                d[i] = d[x] + 1;
                Q.push(i);
                v[i] = 1;
            }
    }
}

int main()
{
    cin >> n >> m >> k >> vi;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }

    for(int i = 1 ; i <= k ; i++)
    {
        cin >> x;
        sg[x] = 1;
    }

    for(int i = 1 ; i <= vi ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
                d[j] = v[j] = 0;
        cin >> p >> q;
        bfs(p , q);
        if(v[q] > 0) rez[++cnt] = 1;
        else rez[++cnt] = 0;
    }

    for(int i = 1 ; i <= cnt; i++)
        if(rez[i] == 1) cout << "DA" << '\n';
    else cout << "NU" << '\n';

}
